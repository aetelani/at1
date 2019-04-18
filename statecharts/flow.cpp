//
// Statemachine code from reading SCXML file 'flow.scxml'
// Created by: The Qt SCXML Compiler version 1 (Qt 5.12.2)
// WARNING! All changes made in this file will be lost!
//

#include "flow.h"

#include <qscxmlinvokableservice.h>
#include <qscxmltabledata.h>
#include <QScxmlNullDataModel>

#if !defined(Q_QSCXMLC_OUTPUT_REVISION)
#error "The header file 'flow.scxml' doesn't include <qscxmltabledata.h>."
#elif Q_QSCXMLC_OUTPUT_REVISION != 1
#error "This file was generated using the qscxmlc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The qscxmlc has changed too much.)"
#endif

struct flow::Data: private QScxmlTableData {
    Data(flow &stateMachine)
        : stateMachine(stateMachine)
    {}

    void init() {
        stateMachine.setTableData(this);
        stateMachine.setDataModel(&dataModel);
    }

    QString name() const override final
    { return string(0); }

    QScxmlExecutableContent::ContainerId initialSetup() const override final
    { return -1; }

    QScxmlExecutableContent::InstructionId *instructions() const override final
    { return theInstructions; }

    QScxmlExecutableContent::StringId *dataNames(int *count) const override final
    { *count = 0; return dataIds; }

    QScxmlExecutableContent::EvaluatorInfo evaluatorInfo(QScxmlExecutableContent::EvaluatorId evaluatorId) const override final
    { Q_ASSERT(evaluatorId >= 0); Q_ASSERT(evaluatorId < 0); return evaluators[evaluatorId]; }

    QScxmlExecutableContent::AssignmentInfo assignmentInfo(QScxmlExecutableContent::EvaluatorId assignmentId) const override final
    { Q_ASSERT(assignmentId >= 0); Q_ASSERT(assignmentId < 0); return assignments[assignmentId]; }

    QScxmlExecutableContent::ForeachInfo foreachInfo(QScxmlExecutableContent::EvaluatorId foreachId) const override final
    { Q_ASSERT(foreachId >= 0); Q_ASSERT(foreachId < 0); return foreaches[foreachId]; }

    QString string(QScxmlExecutableContent::StringId id) const override final
    {
        Q_ASSERT(id >= QScxmlExecutableContent::NoString); Q_ASSERT(id < 5);
        if (id == QScxmlExecutableContent::NoString) return QString();
        return QString({static_cast<QStringData*>(strings.data + id)});
    }

    const qint32 *stateMachineTable() const override final
    { return theStateMachineTable; }

    QScxmlInvokableServiceFactory *serviceFactory(int id) const override final;

    flow &stateMachine;
    QScxmlNullDataModel dataModel;

    static QScxmlExecutableContent::ParameterInfo param(QScxmlExecutableContent::StringId name,
                                                        QScxmlExecutableContent::EvaluatorId expr,
                                                        QScxmlExecutableContent::StringId location)
    {
        QScxmlExecutableContent::ParameterInfo p;
        p.name = name;
        p.expr = expr;
        p.location = location;
        return p;
    }

    static QScxmlExecutableContent::InvokeInfo invoke(
            QScxmlExecutableContent::StringId id,
            QScxmlExecutableContent::StringId prefix,
            QScxmlExecutableContent::EvaluatorId expr,
            QScxmlExecutableContent::StringId location,
            QScxmlExecutableContent::StringId context,
            QScxmlExecutableContent::ContainerId finalize,
            bool autoforward)
    {
        QScxmlExecutableContent::InvokeInfo i;
        i.id = id;
        i.prefix = prefix;
        i.expr = expr;
        i.location = location;
        i.context = context;
        i.finalize = finalize;
        i.autoforward = autoforward;
        return i;
    }

    static qint32 theInstructions[];
    static QScxmlExecutableContent::StringId dataIds[];
    static QScxmlExecutableContent::EvaluatorInfo evaluators[];
    static QScxmlExecutableContent::AssignmentInfo assignments[];
    static QScxmlExecutableContent::ForeachInfo foreaches[];
    static const qint32 theStateMachineTable[];
    static struct Strings {
        QArrayData data[5];
        qunicodechar stringdata[61];
    } strings;
};

flow::flow(QObject *parent)
    : QScxmlStateMachine(&staticMetaObject, parent)
    , data(new Data(*this))
{ qRegisterMetaType<flow *>(); data->init(); }

flow::~flow()
{ delete data; }

QScxmlInvokableServiceFactory *flow::Data::serviceFactory(int id) const
{
    Q_UNUSED(id);
    Q_UNREACHABLE();
}

qint32 flow::Data::theInstructions[] = {
12, 4, -1, -1, 0
};

QScxmlExecutableContent::StringId flow::Data::dataIds[] = {
-1
};

QScxmlExecutableContent::EvaluatorInfo flow::Data::evaluators[] = {
{ -1, -1 }
};

QScxmlExecutableContent::AssignmentInfo flow::Data::assignments[] = {
{ -1, -1, -1 }
};

QScxmlExecutableContent::ForeachInfo flow::Data::foreaches[] = {
{ -1, -1, -1, -1 }
};

#define STR_LIT(idx, ofs, len) \
    Q_STATIC_STRING_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(Strings, stringdata) + ofs * sizeof(qunicodechar) - idx * sizeof(QArrayData)) \
    )
flow::Data::Strings flow::Data::strings = {{
STR_LIT(0, 0, 4), STR_LIT(1, 5, 7), STR_LIT(2, 13, 4), STR_LIT(3, 18, 7),
STR_LIT(4, 26, 33)
},{
0x66,0x6c,0x6f,0x77,0, // 0: flow
0x52,0x75,0x6e,0x6e,0x69,0x6e,0x67,0, // 1: Running
0x45,0x78,0x69,0x74,0, // 2: Exit
0x46,0x69,0x6e,0x61,0x6c,0x5f,0x33,0, // 3: Final_3
0x66,0x69,0x6e,0x61,0x6c,0x20,0x69,0x6e,0x73,0x74,0x72,0x75,0x63,0x74,0x69,0x6f,0x6e,0x20,0x69,0x6e,0x20,0x73,0x74,0x61,0x74,0x65,0x20,0x28,0x6e,0x6f,0x6e,0x65,0x29,0 // 4: final instruction in state (none)
}};

const qint32 flow::Data::theStateMachineTable[] = {
	0x1, // version
	0, // name
	0, // data-model
	6, // child states array offset
	1, // transition to initial states
	-1, // initial setup
	0, // binding
	-1, // maxServiceId
	14, 2, // state offset and count
	36, 2, // transition offset and count
	48, 11, // array offset and size

	// States:
	1, -1, 0, -1, -1, -1, -1, -1, -1, 4, -1,
	3, -1, 2, -1, -1, -1, -1, 0, -1, -1, -1,

	// Transitions:
	2, -1, 1, 0, 0, -1, 
	-1, -1, 2, -1, 9, -1, 

	// Arrays:
	1, 1, 
	1, 2, 
	1, 0, 
	2, 0, 1, 
	1, 0, 

	0xc0ff33 // terminator
};

struct qt_meta_stringdata_flow_t {
    QByteArrayData data[8];
    unsigned char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_flow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_flow_t qt_meta_stringdata_flow = {
    {
QT_MOC_LITERAL(0, 0, 4), // "flow"
QT_MOC_LITERAL(1, 5, 14), // "RunningChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "active"
QT_MOC_LITERAL(4, 28, 14), // "Final_3Changed"
QT_MOC_LITERAL(5, 43, 6), // "parent"
QT_MOC_LITERAL(6, 50, 7), // "Running"
QT_MOC_LITERAL(7, 58, 7) // "Final_3"
    },{
0x66,0x6c,0x6f,0x77,0, // 0: flow
0x52,0x75,0x6e,0x6e,0x69,0x6e,0x67,0x43,0x68,0x61,0x6e,0x67,0x65,0x64,0, // 1: RunningChanged
0, // 2: 
0x61,0x63,0x74,0x69,0x76,0x65,0, // 3: active
0x46,0x69,0x6e,0x61,0x6c,0x5f,0x33,0x43,0x68,0x61,0x6e,0x67,0x65,0x64,0, // 4: Final_3Changed
0x70,0x61,0x72,0x65,0x6e,0x74,0, // 5: parent
0x52,0x75,0x6e,0x6e,0x69,0x6e,0x67,0, // 6: Running
0x46,0x69,0x6e,0x61,0x6c,0x5f,0x33,0 // 7: Final_3
    }};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_flow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   33, // properties
       0,    0, // enums/sets
       1,   41, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // constructors: parameters
    0x80000000 | 2, QMetaType::QObjectStar,    5,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x006a6001,
       7, QMetaType::Bool, 0x006a6001,

 // properties: notify_signal_id
       0,
       1,

 // constructors: name, argc, parameters, tag, flags
       0,    1,   30,    2, 0x0e /* Public */,

       0        // eod
};

void flow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { flow *_r = new flow((*reinterpret_cast< QObject **>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        flow *_t = static_cast<flow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: QMetaObject::activate(_o, &staticMetaObject, 0, _a); break;
        case 1: QMetaObject::activate(_o, &staticMetaObject, 1, _a); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        Q_UNUSED(result);
        Q_UNUSED(func);
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        flow *_t = static_cast<flow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isActive(0); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isActive(1); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject flow::staticMetaObject = {
    { &QScxmlStateMachine::staticMetaObject, qt_meta_stringdata_flow.data,
      qt_meta_data_flow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *flow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *flow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, reinterpret_cast<const char *>(
            qt_meta_stringdata_flow.stringdata0)))
        return static_cast<void*>(const_cast< flow*>(this));
    return QScxmlStateMachine::qt_metacast(_clname);
}

int flow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScxmlStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}


