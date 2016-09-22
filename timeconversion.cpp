#include "timeconversion.h"
#include <QDebug>
#include <QDateTime>

TimeConversion::TimeConversion()
{

}

QString TimeConversion::getInternetTime() {
    QDateTime now;
    QDateTime baseTime;
    now = now.currentDateTime().toTimeSpec(Qt::UTC);
    baseTime = now.addSecs(3600);
    int hour = baseTime.time().hour();
    int minute = baseTime.time().minute();
    int second = baseTime.time().second();
    int internetTime = ((hour  * 3600) + (minute * 60) + (second)) / 86.4;
    QString returnTime = QString(printf("@%03d",internetTime));
    return returnTime;
}
