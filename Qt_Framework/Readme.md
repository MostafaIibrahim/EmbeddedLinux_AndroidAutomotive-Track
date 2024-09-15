# Qt Framework

### What is Qt
Qt is a cross-platform application development framework that provides a comprehensive set of libraries and tools for building GUI applications. It is widely used for developing desktop applications, mobile applications, and embedded systems.
### Key Features
- **Cross-platform**: Qt applications can run on Windows, macOS, Linux, Android, and iOS
- **GUI Library**: Qt provides a comprehensive set of GUI components, including widgets, layouts.
- **Multimedia**: Qt provides a set of multimedia libraries for playing audio and video
- **Network**: Qt provides a set of network libraries for TCP/IP, UDP, and other protocols

1. Modules
2. Libraries
3. tools

1. Modules: Header Files
- Qt includes a large number of modules, each with its own set of header files.
- These modules are organized into categories, such as GUI, Network, and Database.
- Each module has its own set of classes, functions, and macros.
1.1) Qt Core --> for non gui application
1.2) Qt Widget --> for GUI application for Disktop applications, But cannot respond for touching
1.3) Qt quick --> for GUI application, it provides touching --> We will focus right here.

- These two modules (Widget and Quick) Inherit from Qt core and exteneded their functionality so their base is the Qt core.
- Create a GUI with button
```cpp
#include <QPushButton>
int main(){
QPushButton button("press");
button.show();
}
```
* That's How we create Button.

### What is Libraries
- Qt includes a large number of libraries, each with its own set of functions and classes.
- These libraries are organized into categories, such as GUI, Network, and Database.
- Each library has its own set of functions and classes.

### What is Qmake 
- Qmake is a utility sa build system that is used to build Qt applications.
- Qmake takes main.cpp and file.pro as an input and it generates Makefile which links with used libraries to compile and generate executable.

### What are tools
- Qt includes a number of tools, such as the moc (Meta-object-compiler) and rcc(Qt resource compiler)
- These tools are used to generate code and resources that are used by Qt applications.
- The moc is used to generate code that is used by Qt's meta-object system.
- The rcc is used to generate resources, such as images and strings, that are used by Qt applications.
- Qt Designer is a tool that is used to design GUI applications.
- Qt Creator is a tool that is used to develop Qt applications.

-------------------------------------------------------------------------------------------------
### a.exec()
- This is the main event loop of the application.
- It is responsible for processing events, such as mouse clicks and key presses.
- It is also responsible for updating the GUI and handling user input.
- The event loop is the core of any GUI application, and it is what makes the application responsive
- The event loop is a loop that runs until the application is closed.
- If an event is found, the application processes it and updates the GUI accordingly.

### qInfo()
- This is a function that is used to print information to the console.
- It is used to print information to the console, such as debug messages or error messages.
- It is a convenient way to print information to the console without having to use a debugger.

### What are differences between qInfo and cout?
- qInfo is a function that is used to print information to the console, while cout is a function that is used to print information to the console in C++.
- qInfo is a Qt function, while cout is a C++ function.
- qInfo is a more convenient way to print information to the console in a Qt application,
while cout is a more general-purpose way to print information to the console in a C++ application.

- qDebug()

```c++
qInfo() << "Hello from Info"; // --> for user
qDebug() << "hello from debug" ;  //--> Information for debugger
qWarning() << "Hello from warning"; //--> Warning for user
qCritical() << "Hello from critical"; //--> Critical for user
qFatal() << "Hello from fatal"; //--> Fatal for user
```
qfetal() 
- This is a function that is used to print fatal error messages to the console.
- It takes an action and Stop the application

- These functions have handelers that is used to handle these errors

-------------------------------------------------------------------------------------------------
#include<QString>
- This is a directive that includes the QString class from the Qt library.

- QString class --> gives more functions
- This is a class that is used to represent a string in Qt.
- It is a convenience class that provides a number of useful functions for working with strings.
**All function is using QString that's why we won't use String

-------------------------------------------------------------------------------------------------
### How to add new class
- project --> add new 
- Select class
- add class 

### Signals and Slots
- Signals are used to notify other objects that something has happened.
- Slots are used to handle signals.
- Signals and slots are connected using the connect() function.

* We should Enable signals and slots inside class

- **Connect function takes 4 Parameters**
- 1st parameter is the object that is emitting the signal
- 2nd parameter is the signal that is being emitted
- 3rd parameter is the object that is receiving the signal
- 4th parameter is the slot that is being called
- Disconnect function

* From the same signal you can have multiple slots(Handlers).

So Signals and slots are like Call-back mechanism but it's much more easier

### Steps of implementing Signals and slots
1. Enable Signals and Slots mechanism inside ur class
2. Define signals and slots
Signals are prototypes that don't have implementation, While slots have implemenetation
3. Connect Signals and Slots
4. Emit the signals to invoke the slots
5. Disconnect the signals and slots section
```c++
#include<QObject>

class ahmed:public QObject{
    Q_Object // This is the macro inside orivaate section

    public:
        expilict mobile(QObject *parent = nullptr);
        void call(QString *name);
        void send(QString *name);
        void recieve(QString *name);
    signals:
    // Definition of signals
    public slots:
    //definition of slots
    //These section are available because of inheriting QObject
}
```
### Connection Types 
- **AutoConnection:** This means that the connection type is automatically chosen based on the type of the signal and the slot. --> it choose (Direct connection - Queued connection)
- **QueuedConnection:** This is the default connection type. It means that the signal is emitted
and then the slot is called. This is the most common connection type.
- **DirectConnection:** This means that the signal is emitted and then the slot is called immediately. at the same thread.
- **BlockingQueuedConnection:** This means that the signal is emitted and then the slot is called but the execution of the program is blocked until the slot is finished.
- **UniqueConnection:** This means that the signal and slot can only be connected once. for the same Object.
- **NoAutoConnection:** This means that the connection type is not automatically chosen.
- **BlockingConnection:** This means that the signal is emitted and then the slot is called but the execution of the program is blocked until the slot is finished.
