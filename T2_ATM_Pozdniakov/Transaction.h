#pragma once


#include"Card.h"

using namespace std;

class Transaction
{

private:
	QString from;
	QString to;
    long sum;
	QString dateTime;

public:
	Transaction() {};

    Transaction(const QString& from, const QString& to, const long double sum, const QString& dateTime) :
		from(from), to(to), sum(sum), dateTime(dateTime)
	{};

    Transaction(const char* from, const char* to, const long double sum, const char* dateTime) :
		from(QString(from)), to(QString(to)), sum(sum), dateTime(QString(dateTime))
	{};

    ~Transaction() {};

    QString getTo()
    {
        return to;
    }
    QString getFrom()
    {
        return from;
    }
    long getSum()
    {
        return sum;
    }
    QString getDatetime()
    {
        return dateTime;
    }

    QString getToAndSum()
    {
        QString res;
        res += "Receiver: ";
        res += to;
        res += "\nAmount: ";
        QString sum_qstr = QString::number(sum);
        res += sum_qstr;
        return res;
    }

    QString print()
    {
        QString res;
        res += "Sender: ";
        res += from;
        res += "\nReceiver: ";
        res += to;
        res += "\nSum: ";
        QString str = "%1";
        res += str.arg(sum);
        res += "\nDate: ";
        res += dateTime + "\n";
        return res;
    }
};
