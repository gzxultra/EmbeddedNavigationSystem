#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QtXml/QtXml>
#include <QXmlStreamReader>
#include <iostream>
#include <QListWidget>
#include <QLineEdit>
#include <QDebug>
#include <QDir>
#include <QObject>
#include <QtNetwork>

class XmlParser : public QObject
{
    Q_OBJECT
public:
    explicit XmlParser(QObject *parent = 0);
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
#endif // XMLPARSER_H
