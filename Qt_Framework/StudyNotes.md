# Qcore --> Is the base header
- QCoreApplication --> Class provides event loop for non GUI application, all events at OS and other sources are processed and dispatched

### Basic Qt Classes

* QDeubg --> {qInfo() , qDebug(), qWarning, qCritical,qFetal}
- This library is used for logging, which is included for any printing methods

* QString 

* QDate


# Signals  and Slots mechanism

* An event occurs and sends a Signal, A particular Slot handle this Signal. Slot is a function that is called in response to Particular Signal.

### Steps how to use Signals and Slots mechanism

1. Enable Signal and Slots mechanism:
* Include the base class that has this mechanism --> QObject
* Write in private section The Q_Object macro.
- MOC ( Meta-Object Compiler ) supplies each QObject subclass with the necessary code to implement Signals and Slots.  
- Moc --> Moc is a tool that read C++ header file, When Moc find any class has Q_Object macro, it producecs a C++ source file containing hte meta-Object code for those classes.
```cpp
class test: public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);
public slots:

signals:

};
```
2. Connect the slots and signals
- In order to connect signal to slot we need to use this function QObject::connect();
```cpp
connect(&objec1,&signal1,&obj2,&slot1);
```

3. Emit the signal to envoke the slots
- In order to send a signal, you must call the signal function with emit keyword

### Study how to compile and what happens behind the scens

## PS --> You can see the full exercise over slots and signals in First_Class_ex file
