#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
// class of xml parser
#include <QtXml/QtXml>
#include <QXmlStreamReader>
#include <iostream>
#include <QListWidget>
#include <QDebug>
#include <QDir>
class XmlStreamReader
{
public:
    XmlStreamReader(QListWidget *list);
    XmlStreamReader();
    bool readFile(const QString &fileName);
    void setShowWidget(QListWidget *list);

private:
    void readPlaceSuggestionResponse();
    void readResultElement();

    void readNameElement(QListWidget *parent);
    void skipUnknownElement();



    QXmlStreamReader reader;
    QListWidget *listWidget;

};

#endif // XMLSTREAMREADER_H
