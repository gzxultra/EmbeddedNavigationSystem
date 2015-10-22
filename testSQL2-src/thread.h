#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
public:
    Thread();

    void setMessage(const QString &message);
    void stop();

protected:
    void run();

private:
    QString messageStr;
    volatile bool stopped;
};

#endif // THREAD_H
