#pragma once
#include<QtSql>
#include <QDateTime>
#include <QDebug>
#include "Card.h"
#include "Sequence.h"
#include "Transaction.h"
#include "Account.h"

class Bank
{

private:

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

	int accounts = 0;
	int cards = 0;
	int transactions = 0;
	bool isOk;
    Card currentCard;

public:

	Bank()
    {
        QSqlQuery a_query;
        db.setDatabaseName("/Users/nikkirpa/Desktop/MOOP_final_project/T2_ATM_Pozdniakov/db.db");
        db.open();
//        a_query.exec("CREATE TABLE CARDS (card_id VARCHAR (45) PRIMARY KEY UNIQUE NOT NULL, pin VARCHAR (45) NOT NULL, sum INTEGER NOT NULL, isActive BOOLEAN NOT NULL, user_id INTEGER REFERENCES ACCOUNTS (account_id) NOT NULL);");
//        a_query.exec("TRUNCATE TABLE ACCOUNTS;");
//        a_query.exec("CREATE TABLE ACCOUNTS (account_id INTEGER PRIMARY KEY UNIQUE NOT NULL, Name VARCHAR (255));");
//        a_query.exec("CREATE TABLE TRANSACTIONS (sender VARCHAR (45) REFERENCES CARDS NOT NULL, receiver VARCHAR (45) REFERENCES CARDS NOT NULL, sum DOUBLE NOT NULL, dateTime DATETIME NOT NULL, transaction_id INTEGER PRIMARY KEY NOT NULL UNIQUE);");

		isOk = a_query.exec("SELECT COUNT (*) FROM ACCOUNTS");
		a_query.next();
		accounts = a_query.value(0).toInt();
		isOk = a_query.exec("SELECT COUNT(*) FROM CARDS");
		a_query.next();
		cards = a_query.value(0).toInt();
		isOk = a_query.exec("SELECT COUNT(*) FROM TRANSACTIONS");
		a_query.next();
		transactions = a_query.value(0).toInt();
		a_query.finish();

		qDebug() << accounts << '\n';
		qDebug() << cards << '\n';
		qDebug() << transactions << '\n';

	}

	bool addAccount(const char* name)
	{
        QSqlQuery a_query;
        QString str_insert = "INSERT INTO ACCOUNTS (account_id, Name) "
            "VALUES (%1, '%2');";
        QString str = str_insert.arg(QString::number(accounts))
                .arg(name);
        bool res = a_query.exec(str);
       
        qDebug() << a_query.lastError();
		a_query.clear();
		accounts++;

        return  res;
	};

    bool addCard(const char* card_id, const char* pin, long sum, bool isActive, int user_id)
    {
		QSqlQuery a_query;
		QString str_insert = "INSERT INTO CARDS (card_id, pin, summ, isActive, user_id) "
			"VALUES (%1, '%2', %3, %4, %5);";
		QString str = str_insert.arg(card_id)
			.arg(pin)
			.arg(QString::number(sum))
			.arg(isActive)
			.arg(QString::number(user_id));
		bool res = a_query.exec(str);
		a_query.clear();
		cards++;

		return res;
	};
	
	bool doTransaction(const char* sender, const char* reciever, const int sum)
	{
		bool isOk = false;

		QSqlDatabase::database().transaction();
		QSqlQuery a_query;
        QString str_insert = "INSERT INTO TRANSACTIONS (sender, reciever, sum, dateTime, transaction_id) "
			"VALUES ('%1', '%2', %3, '%4', %5);";
		QString str = str_insert.arg(sender)
			.arg(reciever)
			.arg(sum)
			.arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
			.arg(transactions + 1);
		isOk = a_query.exec(str);
		QString str_from = "UPDATE CARDS SET summ = summ+%1 WHERE card_id = '%2'";
        str = str_from.arg(-sum)
                .arg(sender);
        isOk = isOk && a_query.exec(str);

		QString str_to = "UPDATE CARDS SET summ = summ+%1 WHERE card_id = '%2'";
        str = str_to.arg(sum)
                .arg(reciever);
        isOk = isOk && a_query.exec(str);
        if(isOk)
        {
             QSqlDatabase::database().commit();
        }
        else
        {
            QSqlDatabase::database().rollback();
        }
        qDebug() << a_query.lastError();
        transactions++;
        currentCard.setSum(currentCard.getSum() - sum);

        return isOk;
	};	


    Transaction getLastTransaction(const char* card)
    {
        Sequence<Transaction> *seq = new Sequence<Transaction>();
        QSqlQuery a_query;
        Transaction transactions;
        QString userid = a_query.value(0).toString();
        QString str_get = "SELECT * FROM TRANSACTIONS WHERE sender = %1 AND dateTime = "
                          "(SELECT MAX(dateTime) FROM TRANSACTIONS WHERE sender = %1)";
        QString str = str_get.arg(card);
        isOk = a_query.exec(str);
        while(isOk && a_query.next())
        {
            Transaction t(a_query.value(0).toString(),
                          a_query.value(1).toString(),
                          a_query.value(2).toLongLong(),
                          a_query.value(4).toString());
            seq->add(t);
        }
        return seq->operator[](0);
    };



    bool getCard(const char* id, const char* pin, Card& target)
    {
		QSqlQuery a_query;
		QString str_select = "SELECT * FROM CARDS WHERE card_id = '%1' AND pin = '%2';";
		QString str = str_select.arg(id)
			.arg(pin);
		bool isOk = a_query.exec(str);

		qDebug() << a_query.lastError();

        if (isOk && a_query.next())
		{
			QString cardId = a_query.value(0).toString();
			qDebug() << cardId << '\n';
			QString pin = a_query.value(1).toString();
			long sum = a_query.value(2).toInt();
			bool isActive = a_query.value(3).toBool();
			int userId = a_query.value(4).toInt();
			Card res = Card(cardId, pin, sum, isActive, userId);
			target = res;
            currentCard = res;
			return true;
		}
		else
		{
			return false;
		}	
	};



    bool isCard(QString id)
	{
		QSqlQuery a_query;
		QString str_select = "SELECT * FROM CARDS WHERE card_id = '%1';";
		QString str = str_select.arg(id);
		bool isOk = a_query.exec(str);
		isOk = isOk && a_query.next();

        return isOk;
    }



    long getSum(QString id)
    {
        QSqlQuery a_query;
        QString str_select = "SELECT * FROM CARDS WHERE card_id = '%1';";
        QString str = str_select.arg(id);
        long sum = a_query.exec(str);
        sum = sum && a_query.next();

        return sum;
    }


    Card get_current_card() {return currentCard; }


    bool set_current_card(const char* id)
    {
        QSqlQuery a_query;
        QString str_select = "SELECT * FROM CARDS WHERE card_id = '%1'";
        QString str = str_select.arg(id);
        bool isOk = a_query.exec(str);

        //qDebug() << a_query.lastError();

        if (isOk && a_query.next())
        {
            QString cardId = a_query.value(0).toString();
            qDebug() << cardId << '\n';
            QString pin = a_query.value(1).toString();
            long sum = a_query.value(2).toInt();
            bool isActive = a_query.value(3).toBool();
            int userId = a_query.value(4).toInt();
            Card res = Card(cardId, pin, sum, isActive, userId);
            currentCard = res;
            return true;
        }
        else
        {
            return false;
        }
    };


	bool updateSum(const char* id, int sum)
	{
		if (isCard(id))
		{
			QSqlQuery a_query;
			QString str_update = "UPDATE CARDS SET summ = summ+%1 WHERE card_id = '%2'";
			QString str = str_update.arg(sum)
				.arg(id);
            currentCard.setSum(sum+currentCard.getSum());
			return a_query.exec(str);
		}
        else
        {
            return false;
        }
    };


    bool activateCard(QString id, bool activate)
	{
		if (isCard(id))
		{
			QSqlQuery a_query;
			QString str_update = "UPDATE CARDS SET isActive = %1 WHERE card_id = '%2'";
			QString str = str_update.arg(activate)
			.arg(id);
            currentCard.setIsActive(activate);
			return a_query.exec(str);
		}
        else
        {
            return false;
        }
    };


    void change_pin(QString id, QString new_pin)
    {
        if(isCard(id))
        {
            QSqlQuery a_query;
            QString str_update = "UPDATE CARDS SET pin = %1 WHERE card_id = '%2'";
            QString str = str_update.arg(new_pin).arg(id);
            isOk = a_query.exec(str);
            //qDebug() << a_query.lastError();
            //qDebug() << new_pin;
            currentCard.setPin(new_pin);
        }
    };


    Sequence<Transaction> &get_my_info_transactions(QString id)
    {
        Sequence<Transaction> * seq = new Sequence<Transaction>();
        QSqlQuery a_query;
        Transaction transactions;
        QString userid = a_query.value(0).toString();
        QString str_get = "SELECT * FROM TRANSACTIONS WHERE sender = %1";
        QString str = str_get.arg(id);
        isOk = a_query.exec(str);
        while(isOk && a_query.next())
        {
            Transaction t(a_query.value(0).toString(),
                          a_query.value(1).toString(),
                          a_query.value(2).toLongLong(),
                          a_query.value(4).toString());
            seq->add(t);
        }
        return *seq;
    };


    Sequence<Card> &get_my_info_cards(QString id)
    {
        Sequence<Card> * seq = new Sequence<Card>();
        if(isCard(id))
        {
            QSqlQuery a_query;
            QString str_get_id = "SELECT user_id FROM CARDS WHERE card_id = '%1'";
            QString str = str_get_id.arg(id);
            bool isOk = a_query.exec(str);
            Card card;

            if (isOk && a_query.next())
            {
                QString userid = a_query.value(0).toString();
                QString str_get = "SELECT * FROM CARDS WHERE user_id = %1";
                str = str_get.arg(userid);
                isOk = a_query.exec(str);

                while(isOk && a_query.next())
                {
                    Card c(a_query.value(0).toString(),
                           a_query.value(1).toString(),
                           a_query.value(2).toLongLong(),
                           a_query.value(3).toBool(),
                           a_query.value(4).toInt());
                    seq->add(c);
                }
            }
        }
        return *seq;
    };


    Sequence<Account> &get_my_info_account(QString id)
    {
        Sequence<Account> * seq = new Sequence<Account>();
        if(isCard(id))
        {
            QSqlQuery a_query;
            QString str_get_id = "SELECT user_id FROM CARDS WHERE card_id = '%1'";
            QString str = str_get_id.arg(id);
            bool isOk = a_query.exec(str);

            if (isOk && a_query.next())
            {
                QString userid = a_query.value(0).toString();
                QString str_get = "SELECT * FROM ACCOUNTS WHERE account_id = %1";
                str = str_get.arg(userid);
                isOk = a_query.exec(str);

                if(isOk && a_query.next())
                {
                    Account a(a_query.value(0).toInt(), a_query.value(1).toString());
                    seq->add(a);
                }
            }
        }
        return *seq;
    };


    QString *get_all_blocked()
    {
        QSqlQuery a_query;
        QString str = "SELECT card_id FROM CARDS WHERE isActive = 0";
        bool isOk = a_query.exec(str);

        //qDebug() << a_query.lastError();

        Sequence<QString> seq(1);
        QString cardId;

        if (isOk && a_query.next())
        {
            cardId = a_query.value(0).toString();
            seq.add(cardId);
        }
        QString *array = new QString[seq.capacity()]();

        for(size_t i=0; i<seq.capacity(); i++)
        {
            array[i] = seq[i];
        }

        //qDebug() << sizeof(array);

        return array;
    }

};
