#pragma once
#include <QtCore/qstring.h>
#include "Card.h"

class Account
{

private:
	int id;
	QString name;

public:
    Account() {};
    Account(const int id, const QString& name) :
        id(id), name(name)  {};

    ~Account() {};

    QString print()
    {
        QString res;
        res += "Name: ";
        res += name;
        QString str = "%1";
        res += ", id: ";
        res += str.arg(id) + "\n";
        return res;
    }
};
