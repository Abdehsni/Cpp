#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include "observer.h"

namespace observer{
class Observer;

/*!
 * \brief abstract class of all  Observable
 */
class Observable {
public:

    /*!
     * \brief virtual destructor.
     */
    virtual ~Observable() = default;

    /*!
     * \brief constructor with copy.
     */
    Observable(const Observable &) = default;


    /*!
     * \brief Adds an observer to the model
     * \param obs the observer to add
     */
    virtual void addObserver( Observer * obs) final;

    /*!
     * \brief Removes an observer from the model
     * \param obs the observer to remove
     */
    virtual void removeObserver(Observer *obs) final;

protected:
    /*!
     * \brief protected constructor to skip put heritage instanciation.
     */
    Observable() = default;


    std::set<Observer *> observers_ { };

    /*!
     * \brief function that notifies all observer a state changement.
     */
    virtual void notifyAll() const final;

};
}
#endif // OBSERVABLE_H
