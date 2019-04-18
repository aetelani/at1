//
// Statemachine code from reading SCXML file 'flow.scxml'
// Created by: The Qt SCXML Compiler version 1 (Qt 5.12.2)
// WARNING! All changes made in this file will be lost!
//

#ifndef FLOW_H
#define FLOW_H

#include <QScxmlStateMachine>
#include <QString>
#include <QVariant>

class flow: public QScxmlStateMachine
{
    /* qmake ignore Q_OBJECT */
    Q_OBJECT
    Q_PROPERTY(bool Running)
    Q_PROPERTY(bool Final_3)


public:
    Q_INVOKABLE flow(QObject *parent = 0);
    ~flow();



Q_SIGNALS:


private:
    struct Data;
    friend struct Data;
    struct Data *data;
};

Q_DECLARE_METATYPE(::flow*)

#endif // FLOW_H
