#ifndef OBSERVER_H
#define OBSERVER_H

namespace observer{
class Observable;
/*!
 * \brief abstract class of all  Observers
 */
class Observer {
public:

    /*!
     * \brief virtual function updating all observers.
     * \param obs the observed subject.
     */
    virtual void update(const Observable * obs) = 0;

    /*!
     * \brief default virtual destructor.
     */
    virtual ~Observer() = default;

    /*!
     * \brief constructor by copy.
     */
    Observer(const Observer &) = default;

    Observer & operator=(const Observer &) = default;

protected:
    /*!
     * \brief protected constructor to skip out heritage instanciation.
     */
    Observer() = default;
};

}

#endif
