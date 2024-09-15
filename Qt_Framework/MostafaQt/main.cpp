#include <QCoreApplication>
#include <QDate>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDate today = QDate::currentDate();

    qInfo() << "today: " << today;
    qInfo() << "today.addDays(5): " << today.addDays(5);
    qInfo() << "today:addYears(10) " << today.addYears(10);
    // qInfo() << "Mostafa QT";
    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    return a.exec();
}
