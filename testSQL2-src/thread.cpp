/*
#include "thread.h"
#include "QDebug"
#include "iostream"
#include "widget.h"
#include "ui_widget.h"



Thread::Thread()
{
    stopped = false;
}

void Thread::run()
{
    while(!stopped){
        std::cerr << qPrintable(messageStr);
        ui.textBrowser.append("thread\n");
    }
        stopped = false;
    std::cerr << std::endl;
}

void Thread::stop()
{
    stopped = true;
}
*/
