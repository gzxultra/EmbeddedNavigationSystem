#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
// class of xml parser
#include <QtXml/QtXml>
#include <QXmlStreamReader>
#include <iostream>
#include <QListWidget>
#include <QLineEdit>
#include <QDebug>
#include <QDir>
#include <QObject>

class XmlStreamReader : public QObject
{
    Q_OBJECT
public:

    explicit XmlStreamReader(QObject *parent = 0);
    bool readFile(const QString &fileName);
    void setShowWidget(QListWidget *list, QLineEdit *line);

private:
    void readPlaceSuggestionResponse();
    void readResultElement();

    void readNameElement(QListWidget *parent, QLineEdit *line);
    void skipUnknownElement();

    QXmlStreamReader reader;
    QListWidget *listWidget;
    QLineEdit *lineEdit;



};

#endif // XMLSTREAMREADER_H
