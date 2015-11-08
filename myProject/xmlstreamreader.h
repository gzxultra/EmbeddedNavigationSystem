#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
// class of xml parser
#include <QtXml/QtXml>
#include <QXmlStreamReader>
#include <iostream>

class XmlStreamReader
{
public:
    XmlStreamReader();
    bool readFile(const QString &filename);

private:
    void readPlaceSuggestionResponse();
    void readResultElement();

    void readNameElement();
    void skipUnknownElement();

    QXmlStreamReader reader;
};

#endif // XMLSTREAMREADER_H
