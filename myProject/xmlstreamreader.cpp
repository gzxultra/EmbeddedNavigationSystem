#include "xmlstreamreader.h"
/*
XmlStreamReader::XmlStreamReader(QListWidget *list)
{
    listWidget = list;
}
*/
XmlStreamReader::XmlStreamReader(QObject *parent) : QObject(parent)
{
  // default constructor
}

void XmlStreamReader::setShowWidget(QListWidget *list, QLineEdit *line)
{
  this->listWidget = list;
  this->lineEdit = line;
}

bool XmlStreamReader::readFile(const QString &fileName)
{
  QString fileWithAbsoultePath = QDir::currentPath() + '/' + fileName ;
  // qDebug()<<fileWithAbsoultePath;
  QFile file(fileWithAbsoultePath);
  if (!file.open(QFile::ReadOnly | QFile::Text))
  {
    std::cerr << "Error: cannot read file "
              << qPrintable(fileName) << ": "
              << qPrintable(file.errorString())
              << std::endl;
    return false;
  }

  reader.setDevice(&file);



  reader.readNext();
  // if (reader.atEnd())
  // qDebug()<< fileName<< "no content";
  while (!reader.atEnd())
  {
    if (reader.isStartElement())
    {
      if (reader.name() == "PlaceSuggestionResponse")
      {
        readPlaceSuggestionResponse();
      }
      else
      {
        reader.raiseError(QObject::tr("Not a PlaceSuggestionResponse file"));
      }
    } else
    {
      // qDebug()<<"next";
      reader.readNext();
    }
  }

  file.close();
  if (reader.hasError())
  {
    std::cerr << "Error: Failed to parse file "
              << qPrintable(fileName) << ": "
              << qPrintable(reader.errorString()) << std::endl;
    return false;
  }
  else if (file.error() != QFile::NoError)
  {
    std::cerr << "Error: Cannot read file " << qPrintable(fileName)
              << ": " << qPrintable(file.errorString())
              << std::endl;
    return false;
  }
  return true;
}

void XmlStreamReader::readPlaceSuggestionResponse()
{
  reader.readNext();
  while (!reader.atEnd())
  {
    if (reader.isEndElement())
    {
      reader.readNext();
      break;
    }

    if (reader.isStartElement())
    {
      if (reader.name() == "result")
      {
        readResultElement();
      }
      else
      {
        skipUnknownElement();
      }
    }
    else
    {
      reader.readNext();
    }
  }
}

void XmlStreamReader::readResultElement()
{
  reader.readNext();
  while (!reader.atEnd())
  {
    if (reader.isEndElement())
    {
      reader.readNext();
      break;
    }

    if (reader.isStartElement())
    {
      if (reader.name() == "name")
      {
        readNameElement(listWidget, lineEdit);
      }
      else
      {
        skipUnknownElement();
      }
    }
    else
    {
      reader.readNext();
    }
  }
}
void XmlStreamReader::readNameElement(QListWidget *parent, QLineEdit *line)
{
  QString suggestion = reader.readElementText();
  qDebug() << suggestion;

  QListWidgetItem *item = new QListWidgetItem;
  item->setText(suggestion);
  item->setWhatsThis(suggestion + "test");
  parent->addItem(item);


  reader.readNext();

  while (!reader.atEnd())
  {
    if (reader.isEndElement())
    {
      reader.readNext();
      break;
    }

    if (reader.isStartElement())
    {
      if (reader.name() == "name")
        readNameElement(parent, line);
      else
        skipUnknownElement();
    }
    else
    {
      reader.readNext();
    }
  }
}

void XmlStreamReader::skipUnknownElement()
{
  reader.readNext();
  while (!reader.atEnd())
  {
    if (reader.isEndElement())
    {
      reader.readNext();
      break;
    }

    if (reader.isStartElement())
    {
      // self-call
      skipUnknownElement();
    }
    else {
      reader.readNext();
    }
  }
}
