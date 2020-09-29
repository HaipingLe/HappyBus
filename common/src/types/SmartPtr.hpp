//////////////////////////////////////////////////////////////////////
/// @file    SmartPtr.hpp
///
/// @author Hubert lehaiping@126.com

/// @brief
/// Implementing a pointer with reference counting.
/// The raw pointer managed by this will be released when last
/// instance of this object is destroyed.
/// Actually it's very similiar with std::shared_ptr in C++11.
///
/// The management (copy and assignment) of these objects is thread-safe
/// because the reference count is defined as AtomicInteger type.
//////////////////////////////////////////////////////////////////////
#ifndef HAPPYBUS_COMMON_TYPES_SMARTPTR_HPP
#define HAPPYBUS_COMMON_TYPES_SMARTPTR_HPP

#include <cassert>
#include "system/AtomicInteger.hpp"

namespace happybus
{
namespace common
{
namespace types
{
template <typename T>
class SmartPtr
{
public:
    SmartPtr() throw() : mItemPtr(nullptr), mCounterPtr(nullptr) {}

    /**
     * @param[in] Item  element
     */
    explicit SmartPtr(T *Item)
        : mItemPtr(Item)
        , mCounterPtr(nullptr != Item ? new happybus::common::system::AtomicInteger(1) : nullptr) {}

    /**
     * Destroys the object when it isn't referenced anymore by anyone else.
     */
    ~SmartPtr() throw()
    {
        if (nullptr != mCounterPtr && mCounterPtr->decrement() == 1)
        {
            delete mItemPtr;
            mItemPtr = nullptr;
            delete mCounterPtr;
            mCounterPtr = nullptr;
        }
    }

    /**
     * Copy Construtor. References the original Pointer and increments the reference
     * count of this object.
     */
    SmartPtr(const SmartPtr &ptr) throw()
        : mItemPtr(ptr.mItemPtr), mCounterPtr(ptr.mCounterPtr)
    {
        if (nullptr != mCounterPtr)
        {
            ++(*mCounterPtr);
        }
    }

    /**
     * @brief Copy Ctor (different types). Try to copy the given element into
     * this. If successful this object references the original pointer and
     * increments the reference count of this object. Otherwise nothing will be
     * done and this object is nullptr.
     * @param ptr reference to (other SmartPtr) object
     */
    template <typename Y>
    explicit SmartPtr(const SmartPtr<Y> &ptr) throw()
        : mItemPtr(0), mCounterPtr(0)
    {
        mItemPtr = ptr.mItemPtr;
        if (nullptr == mItemPtr)
        {
            mCounterPtr = nullptr;
        }
        else
        {
            mCounterPtr = ptr.mCounterPtr;
            if (nullptr != mCounterPtr)
            {
                ++(*mCounterPtr);
            }
        }
    }

    /** Dynamic cast. Like C++ dynamic_cast for dumb pointers, but returns a smart
     * pointer. */
    template <class Y>
    SmartPtr<Y> dynamicCast() const throw()
    {
        return SmartPtr<Y>(dynamic_cast<Y *>(mItemPtr), mCounterPtr);
    }

    /** Static cast. Like C++ static_cast for dumb pointers, but returns a smart
     * pointer. */
    template <class Y>
    SmartPtr<Y> staticCast() const throw()
    {
        return SmartPtr<Y>(static_cast<Y *>(mItemPtr), mCounterPtr);
    }

    /**
     * @brief Const cast. Like C++ const_cast for dumb pointers, but returns a
     * smart pointer.
     * @return a smart pointer copy with raw pointer's cv-qualifiers modified
     * accordingly.
     */
    template <class Y>
    SmartPtr<Y> constCast() const throw()
    {
        return SmartPtr<Y>(const_cast<Y *>(mItemPtr), mCounterPtr);
    }

    /**
     * @brief a shortcut to constCast-method for just adding constness.
     * @return a smart pointer copy with raw pointer's const-qualification added.
     */
    SmartPtr<const T> asConst() const throw()
    {
        return constCast<const T>();
    }

    //! Convert pointer to bool. One may now use
    //! SmartPtrs in expressions like if (x) ...
    operator bool() const throw()
    {
        return nullptr != mItemPtr;
    }

    //! comparison operators
    bool operator==(SmartPtr<T> const &rhs) const throw()
    {
        return mItemPtr == rhs.mItemPtr;
    }

    bool operator!=(SmartPtr<T> const &rhs) const throw()
    {
        return mItemPtr != rhs.mItemPtr;
    }

    bool operator<(SmartPtr<T> const &rhs) const throw()
    {
        return mItemPtr < rhs.mItemPtr;
    }

    bool operator<=(SmartPtr<T> const &rhs) const throw()
    {
        return mItemPtr <= rhs.mItemPtr;
    }

    bool operator>=(SmartPtr<T> const &rhs) const throw()
    {
        return mItemPtr >= rhs.mItemPtr;
    }

    //! @param[in] Item instance to assign
    //! \note The Pointer given is from then on managed by
    //! this and MUST NOT be manually deleted!
    SmartPtr const &operator=(T *Item)
    {
        if (this->get() != Item)
        {
            if (mCounterPtr != nullptr && mCounterPtr->decrement() == 1)
            {
                // last reference to the object
                delete mItemPtr;
                delete mCounterPtr;
            }

            // reference Item
            mItemPtr = Item;
            mCounterPtr = (nullptr != Item) ? new happybus::common::system::AtomicInteger(1) : 0;
        }

        return *this;
    }

    SmartPtr &operator=(const SmartPtr &ptr)
    {
        if (this != &ptr)
        {
            if (ptr.mCounterPtr != nullptr)
            {
                ++(*ptr.mCounterPtr);
            }

            if (mCounterPtr != nullptr && mCounterPtr->decrement() == 1)
            {
                // last one reference the object
                delete mItemPtr;
                delete mCounterPtr;
            }

            // reference other
            mItemPtr = ptr.mItemPtr;
            mCounterPtr = ptr.mCounterPtr;
        }

        return *this;
    }

    //! Direct access on object members and functions
    //! \note Terminating the program execution if object nullptr
    T *operator->(void)const
    {
        return mItemPtr;
    }

    //! Direct access on object
    //! \note Terminating the program execution if object nullptr
    T &operator*() const
    {
        return *mItemPtr;
    }

    const T *get() const throw()
    {
        return mItemPtr;
    }

    T *get() throw()
    {
        return mItemPtr;
    }

    /**
     * \return The reference count of the referenced object.
     */
    uint32_t getRefCount() const throw()
    {
        uint32_t count = 0;
        if (mCounterPtr)
        {
            count = static_cast<uint32_t>(*mCounterPtr);
        }
        return count;
    }

private:
    SmartPtr(T *pItem, happybus::common::system::AtomicInteger *pCounter) throw() : mItemPtr(pItem), mCounterPtr(0)
    {
        if (mItemPtr != nullptr)
        {
            mCounterPtr = pCounter;
            ++*mCounterPtr;
        }
    }

    /**
     * @brief Need this friend declaration for Copy Ctor (different types).
     */
    template <class Y>
    friend class SmartPtr;

    T *mItemPtr;                                      //referenced element
    happybus::common::system::AtomicInteger *mCounterPtr;  //reference counter
};

/** Pointer address comparator for SmartPtr.
 * This allows you to compare two SmartPtr objects by their pointer addresses,
 * e.g. to use them as keys in a map. There are no further requirements to the
 * pointer type T. You can create a map using this comparator like this:
 *
 * std::map< SmartPtr<SomeComplexType>, uint32_t, SmartPtrAddressComp<NvcResult>
 * > mySmartPtrMap;
 *
 * \tparam T The type of the SmartPtr.
 */
template <class T>
class SmartPtrAddressComp
{
public:
    /** The actual compare operator.
     * This operator compares two SmartPtr by their pointer addresses for "lower
     * than". \param a The left SmartPtr. \param b The right SmartPtr. \return
     * True if a refers to a lower address than b, otherwise false.
     */
    inline bool operator()(const happybus::common::types::SmartPtr<T> &a, const happybus::common::types::SmartPtr<T> &b) const
    {
        // Compare by pointer address
        return (a.get() < b.get());
    }
};

/** Value comparator for SmartPtr.
 * This allows you to compare two SmartPtr objects by their referred values,
 * e.g. to use them as keys in a map. The value type T must be comparable, i.e.
 * an operator< must be provided for it.
 */
class SmartPtrElementComp
{
public:
    /** The actual compare operator.
     * This operator compares two SmartPtr by their referred value for "lower
     * than". \param lhs The left SmartPtr. \param rhs The right SmartPtr. \tparam
     * T The type of the SmartPtr (must provide the operator "<"). \return True if
     * lhs refers to a lower value than rhs, otherwise false.
     */
    template <typename T>
    bool operator()(const happybus::common::types::SmartPtr<T> &lhs, const happybus::common::types::SmartPtr<T> &rhs) const
    {
        return (*lhs < *rhs);
    }
};
}  // namespace types
}  // namespace common
}  // namespace happybus
#endif