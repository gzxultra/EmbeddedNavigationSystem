#include "xmlparser.h"

XmlParser::XmlParser(QObject *parent) : QObject(parent)
{
	// default constructor
}

void XmlParser::setShowWidget(QListWidget *list, QLineEdit *line)
{
	this->listWidget = list;
	this->lineEdit = line;
	// qDebug() << "set output widget.";
}

bool XmlParser::readFile(const QString &fileName)
{
	QString fileWithAbsoultePath = QDir::currentPath() + '/' + fileName ;

	// qDebug()<<fileWithAbsoultePath;
	QFile file(fileWithAbsoultePath);
	// QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		std::cerr << "Error: cannot read file "
		          << qPrintable(fileName) << ": "
		          << qPrintable(file.errorString())
		          << std::endl;
		return false;
	}

	qDebug() << "set file as device.";
	reader.setDevice(&file);



	reader.readNext();

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

void XmlParser::readPlaceSuggestionResponse()
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

void XmlParser::readResultElement()
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
void XmlParser::readNameElement(QListWidget *parent, QLineEdit *line)
{
	QString suggestion = reader.readElementText();
	// qDebug() << "we have come this far.";
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

void XmlParser::skipUnknownElement()
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