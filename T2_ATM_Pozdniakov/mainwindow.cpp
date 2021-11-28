#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix(":/recources/atm.jpg");
    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    set_default();
    setWindowTitle("ATM");
    this->setFixedSize(this->width(), this->height());
    ui->mainWindow->setText("1 -> Check card balance\n\n"
                            "2 -> Withdraw cash\n\n"
                            "3 -> Replenish card\n\n"
                            "4 -> Card transfer\n\n"
                            "5 -> Block card\n\n"
                            "6 -> Change PIN \n\n"
                            "7 -> Other\n\n"
                            "8 -> Exit");


    ui->cash->setText("1 -> 50\n\n"
                      "2 -> 100\n\n"
                      "3 -> 200\n\n"
                      "4 -> 500\n\n"
                      "5 -> 1000\n\n"
                      "6 -> Another amount\n\n"
                      "8 -> Return"
                      );
    ui->other->setText("1 -> Replenish phone number\n\n"
                       "2 -> Send money to charity\n\n"
                       "3 -> Get card info\n\n"
                       "8 -> Return");
    ui->info->setText("");



    {
        QGridLayout *layout = new QGridLayout();
        QPushButton *button_1 = new QPushButton();
        QPushButton *button_2 = new QPushButton();
        QPushButton *button_3 = new QPushButton();
        QPushButton *button_4 = new QPushButton();
        QPushButton *button_5 = new QPushButton();
        QPushButton *button_6 = new QPushButton();
        button_1->setText("10");
        button_2->setText("20");
        button_3->setText("50");
        button_4->setText("100");
        button_5->setText("200");
        button_6->setText("500");
        QSignalMapper* signalMapper = new QSignalMapper (this) ;
        connect(button_1, SIGNAL (clicked()), signalMapper, SLOT (map()));
        connect(button_2, SIGNAL (clicked()), signalMapper, SLOT (map()));
        connect(button_3, SIGNAL (clicked()), signalMapper, SLOT (map()));
        connect(button_4, SIGNAL (clicked()), signalMapper, SLOT (map()));
        connect(button_5, SIGNAL (clicked()), signalMapper, SLOT (map()));
        connect(button_6, SIGNAL (clicked()), signalMapper, SLOT (map()));
        signalMapper -> setMapping (button_1, 10) ;
        signalMapper -> setMapping (button_2, 20) ;
        signalMapper -> setMapping (button_3, 50) ;
        signalMapper -> setMapping (button_4, 100) ;
        signalMapper -> setMapping (button_5, 200) ;
        signalMapper -> setMapping (button_6, 500) ;
        connect (signalMapper, SIGNAL(mappedInt(int)), this, SLOT(change_sum_cash(int))) ;
        layout->addWidget(button_1);
        layout->addWidget(button_2);
        layout->addWidget(button_3);
        layout->addWidget(button_4);
        layout->addWidget(button_5);
        layout->addWidget(button_6);
        cashWidget->setLayout(layout);
        QGridLayout *layoutSettings = new QGridLayout();
        QPushButton *settings_b_1 = new QPushButton("Switch off");
        QString temp = "";
        temp += "Limit for cash withdrawal: ";
        temp += QString::number(limitCash);
        QPushButton *settings_b_2 = new QPushButton(temp);
        temp = "";
        temp += "Limit for cash insert: ";
        temp += QString::number(limitCashInsert);
        QPushButton *settings_b_3 = new QPushButton(temp);
        QPushButton *settings_b_4 = new QPushButton("Exit");
        layoutSettings->addWidget(settings_b_1);
        layoutSettings->addWidget(settings_b_2);
        layoutSettings->addWidget(settings_b_3);
        layoutSettings->addWidget(settings_b_4);
        connect(settings_b_1, SIGNAL (clicked()), this, SLOT (settings_b_1()));
        connect(settings_b_2, SIGNAL (clicked()), this, SLOT (settings_b_2()));
        connect(settings_b_3, SIGNAL (clicked()), this, SLOT (settings_b_3()));
        connect(settings_b_4, SIGNAL (clicked()), this, SLOT (settings_b_4()));
        settingsWidget->setLayout(layoutSettings);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settings_b_1()
{
    if(working){
        QPushButton *q = qobject_cast<QPushButton*>(settingsWidget->children().at(1));
        switch_off();
        working = !working;
        q->setText("Switch on");
    } else {
        QPushButton *q = qobject_cast<QPushButton*>(settingsWidget->children().at(1));
        switch_on();
        working = !working;
        q->setText("Switch off");
    }

}

void MainWindow::settings_b_2()
{
    int res = 0;
    do{
        res = QInputDialog::getInt(this, tr("New limit"),
                                   tr("Limit: "), 0, QLineEdit::Normal);


    } while (res<0);
    if (res != 0){
        limitCash = res;
        QPushButton *q = qobject_cast<QPushButton*>(settingsWidget->children().at(2));
        QString temp = "";
        temp += "Limit for cash withdrawal: ";
        temp += QString::number(limitCash);
        q->setText(temp);
        QMessageBox::about(this, tr("Limit"),
                           tr(temp.toUtf8().data()));
    }
}
void MainWindow::settings_b_3()
{
    int res = 0;
    do{
        res = QInputDialog::getInt(this, tr("New limit"),
                                   tr("Limit: "), 0, QLineEdit::Normal);


    } while (res<0);
    if (res != 0){
        limitCashInsert = res;
        QPushButton *q = qobject_cast<QPushButton*>(settingsWidget->children().at(3));
        QString temp = "";
        temp += "Limit for cash insert: ";
        temp += QString::number(limitCashInsert);
        q->setText(temp);
        QMessageBox::about(this, tr("Limit"),
                           tr(temp.toUtf8().data()));
    }
}

void MainWindow::settings_b_4()
{
    settingsWidget->close();
    this->show();
}

void MainWindow::change_sum_cash(const int a)
{
    ui->sum->setText(QString::number(ui->sum->text().toInt() + a));
    ui->addCash->setText("*Use button \"Insert Cash\"*\nCurrent amount: " + ui->sum->text() + "\n1 Confirm");
    cashWidget->close();
}

void MainWindow::on_insert_card_clicked()
{
    QString text;
    do{
        QInputDialog inp;
        inp.setWindowTitle("Insert Card");
        inp.setLabelText("Card");
        inp.setTextValue("");
        connect(&inp, &QInputDialog::textValueChanged, this, [&inp](const QString text) {

            QString res("");
            for (int i = 0; i<text.length(); i++){
                if( text[i].isDigit()){
                    res +=  text[i];
                }

            }
            if(res.length()>16){
                res = res.left(16);
            }

            inp.setTextValue(res);

        });

        int ret = inp.exec();

        if (ret == QDialog::DialogCode::Accepted )
            text = inp.textValue();
        if (ret == QDialog::DialogCode::Rejected )
            return;
        if(text.length() != 16){
            QMessageBox::warning(this, tr("Error"),
                                 tr("Wrong card number"));
        }else {
            if(!b.isCard(text)) {
                QMessageBox::warning(this, tr("Error"),
                                     tr("Can't find card with this number"));
            } else {
                QByteArray ba = text.toLocal8Bit();
                const char *str = ba.data();
                b.set_current_card(str);
                ui->firstWindow->setText("Enter PIN:\n");
                ui->PIN->setText("");
                ui->settings_btn->setDisabled(true);
                ui->empty->close();
                ui->firstWindow->show();
                ui->pins->setText("3");
                ui->insert_card->setDisabled(true);
                set_button_on();

            }
        }

    } while (text.length() != 16 || text.toULongLong() == 0);
}

void MainWindow::on_screen_1_clicked()
{

    if(!ui->mainWindow->isHidden()){
        if(check_block_card(b.get_current_card().getId()))
        {
            ui->mainWindow->show();
        }
        else
        {
            QString temp ("Card balance: ");
            temp += QString::number(b.get_current_card().getSum());
            QMessageBox::about(this, tr("Balance"),
                               tr(temp.toUtf8().data()));
        }
    } else if(!ui->cards->isHidden()){
        if(check_block_card(b.get_current_card().getId()))
        {
            ui->mainWindow->show();
        }
    } else if(!ui->cash->isHidden()){
        give_cash(50);
    } else if(!ui->addCash->isHidden()){
        give_cash(-(ui->sum->text().toInt()));
        ui->addCash->close();
        ui->mainWindow->show();
        ui->sum->setText("0");
        ui->insert_cash->setDisabled(true);
    } else if(!ui->other->isHidden()){
        int res;
        QString text;
        QRegularExpression rx("(\\+38)?0([0-9]{2}|\\([0-9]{2}\\))[0-9]{7}");
        QRegularExpressionMatch match = rx.match(text);
        do{
            QInputDialog inp;
            inp.setWindowTitle("Phone number");
            inp.setLabelText("Enter phone number");
            inp.setTextValue("");
            connect(&inp, &QInputDialog::textValueChanged, this, [&inp](const QString text) {
                QString res("");
                for (int i = 0; i<text.length(); i++){
                    if( text[i].isDigit()){
                        res +=  text[i];
                    }

                }
                if(res.length()>16){
                    res = res.left(16);
                }

                inp.setTextValue(res);

            });
            int ret = inp.exec();
            if (ret == QDialog::DialogCode::Accepted )
                text = inp.textValue();
            if (ret == QDialog::DialogCode::Rejected )
                return;
            if(!match.hasMatch()){
                QMessageBox::warning(this, tr("Phone number replenished"),
                                   tr("Wrong phone number"));
            }
        } while (!match.hasMatch());
        do{
            res = QInputDialog::getInt(this, tr("Choose amount"),
                                       tr("Amount: "),   0,QLineEdit::Normal);
        } while (res<0);
        if(res != 0){
            QString temp ("Phone number ");
            temp += text;
            temp += " was replenished for ";
            temp += QString::number(res);
            QMessageBox::about(this, tr("Phone number replenished"),
                               tr(temp.toUtf8().data()));
            QByteArray ba = b.get_current_card().getId().toLocal8Bit();
            const char *str = ba.data();
            b.updateSum(str, (-1)*res);
        }
    }
}

void MainWindow::on_screen_2_clicked()
{
    if(!ui->mainWindow->isHidden()){
        if(check_block_card(b.get_current_card().getId()))
        {
            ui->mainWindow->show();
        }
        else
        {
            ui->mainWindow->close();
            ui->cash->show();
        }

    } else if(!ui->cards->isHidden()){
        if(check_block_card(b.get_current_card().getId())) {
            ui->mainWindow->show();
        }
    } else if(!ui->cash->isHidden()){
        give_cash(100);
    } else if(!ui->other->isHidden()){
        int res;
        do{
            res = QInputDialog::getInt(this, tr("Choose amount"),
                                       tr("Amount: "),   0,QLineEdit::Normal);


        } while (res<0);
        if(res != 0){

            QString temp ("You donated for a charity ");
            temp += QString::number(res);
            temp += ". Thank You!";

            QMessageBox::about(this, tr("Charity"),
                               tr(temp.toUtf8().data()));
            QByteArray ba = b.get_current_card().getId().toLocal8Bit();
            const char *str = ba.data();
            b.updateSum(str, (-1)*res);
        }

    }else if(!ui->addCash->isHidden()){
        if (ui->sum->text() == "0"){
            ui->addCash->close();
            ui->mainWindow->show();
            ui->sum->setText("0");
            ui->insert_cash->setDisabled(true);
        }

    }

}

void MainWindow::on_screen_3_clicked()
{
    if(!ui->mainWindow->isHidden()){
        if(check_block_card(b.get_current_card().getId()))
        {
            ui->mainWindow->show();
        }
        else
        {
            ui->mainWindow->close();
            ui->addCash->show();

            ui->insert_cash->setDisabled(false);
            ui->addCash->setText("*Use button \"Insert Cash\"*\nCurrent amount: " + ui->sum->text() + "\n1 Confirm\n2 Exit");
        }


    } else if(!ui->cards->isHidden()){
        if(check_block_card(b.get_current_card().getId()))
        {
            ui->mainWindow->show();
        }
    } else if(!ui->cash->isHidden()){
        give_cash(200);
    } else if(!ui->other->isHidden()){

        ui->other->close();
        ui->info->show();
        ui->info->insertPlainText("Account: \n");
        for(size_t i = 0; i < b.get_my_info_account(b.get_current_card().getId()).sizes(); i++)
        {
            ui->info->insertPlainText(b.get_my_info_account(b.get_current_card().getId())[i].print() + "\n");
        }
        ui->info->insertPlainText("\nCards: \n");
        for(size_t i = 0; i < b.get_my_info_cards(b.get_current_card().getId()).sizes(); i++)
        {
            ui->info->insertPlainText(b.get_my_info_cards(b.get_current_card().getId())[i].print() + "\n");
        }
        ui->info->insertPlainText("\nTransactions: \n");
        for(size_t i = 0; i < b.get_my_info_transactions(b.get_current_card().getId()).sizes(); i++)
        {
            ui->info->insertPlainText(b.get_my_info_transactions(b.get_current_card().getId())[i].print() + "\n");
        }
        ui->info->insertPlainText("\n\nTo exit enter button: 8\n");
    }
}

void MainWindow::on_screen_4_clicked()
{
    if(check_block_card(b.get_current_card().getId()))
    {
        ui->mainWindow->show();
    }
    else
    {

        if(!ui->mainWindow->isHidden()){

            Transaction last_transaction;
            QString card = b.get_current_card().getId();
            int amount;

            QByteArray c = card.toLocal8Bit();
            const char* card_c = c.data();

            last_transaction = b.getLastTransaction(card_c);


            QMessageBox::StandardButton main_button;
              main_button = QMessageBox::question(this, "Transaction", "Do you want to repeat previous transaction?\n\n" + last_transaction.getToAndSum(),
                                            QMessageBox::Yes|QMessageBox::No);
              if (main_button == QMessageBox::Yes) {
                  QByteArray sender =  last_transaction.getFrom().toLocal8Bit();
                  const char *sender_c = sender.data();
                  QByteArray receiver =  last_transaction.getTo().toLocal8Bit();
                  const char *receiver_c = receiver.data();
                  if(b.get_current_card().getSum() < last_transaction.getSum())
                  {
                      QMessageBox::warning(this, tr("Error"),
                                           tr("Not tenough money on current card"));
                  }
                  else
                  {

                      b.doTransaction(sender_c, receiver_c, last_transaction.getSum());
                      QString message = "You send %1 to card %2";
                      QString message_str = message.arg(last_transaction.getSum()).arg(receiver_c);
                      QMessageBox::about(this, tr("Success."),
                                           tr(message_str.toUtf8().data()));
                  }
              } else {
                  do{
                      QInputDialog inp;
                      inp.setWindowTitle("Insert Card");
                      inp.setLabelText("Card");
                      inp.setTextValue("");
                      connect(&inp, &QInputDialog::textValueChanged, this, [&inp](const QString text) {

                          QString res("");
                          for (int i = 0; i<text.length(); i++){
                              if( text[i].isDigit()){
                                  res +=  text[i];
                              }

                          }
                          if(res.length()>16){
                              res = res.left(16);
                          }

                          inp.setTextValue(res);

                      });

                      int ret = inp.exec();

                      if (ret == QDialog::DialogCode::Accepted )
                          card = inp.textValue();
                      if (ret == QDialog::DialogCode::Rejected )
                          return;

                      if(card.length() != 16 ){
                          QMessageBox::warning(this, tr("Error"),
                                               tr("Wrong card number"));
                      }
                      if(b.get_current_card().getId() == card){
                          QMessageBox::warning(this, tr("Error"),
                                               tr("You can't send money to the same card"));


                      }

                  } while (card.length() != 16 || card.toULongLong() == 0 || b.get_current_card().getId()== card);

                  do{
                      amount = QInputDialog::getInt(this, tr("Input amount"),
                                                    tr("Amount: "),   0,QLineEdit::Normal);


                      if(amount == 0) return;
                      if(amount < 0){
                          QMessageBox::warning(this, tr("Error"),
                                               tr("Wrong input amount"));
                      }

                  } while (amount < 0);
                  if(amount > b.get_current_card().getSum())
                  {
                      QMessageBox::warning(this, tr("Error"),
                                           tr("Not enough money on card"));
                  }
                  else
                  {
                      QByteArray ba = b.get_current_card().getId().toLocal8Bit();
                      const char *str = ba.data();
                      QByteArray ba2 = card.toLocal8Bit();
                      const char *str2 = ba2.data();
                      b.doTransaction(str, str2, amount);
                      QString message = "You send %1 to card %2";
                      QString message_str = message.arg(amount).arg(card);
                      QMessageBox::about(this, tr("Success"),
                                           tr(message_str.toUtf8().data()));
                  }

              }

        } else if(!ui->cards->isHidden()){
            check_block_card(b.get_current_card().getId());

        } else if(!ui->cash->isHidden()){
            give_cash(500);
        }
    }
}

void MainWindow::on_screen_5_clicked()
{
    if(!ui->mainWindow->isHidden()){
        bool active = b.get_current_card().getIsActive();
        if(!active)
        {
            currentState = unblockCard;
            ui->mainWindow->hide();
            set_button_on();

            ui->firstWindow->setText("Enter PIN:");
            ui->PIN->setText("");
            ui->firstWindow->show();
        }
        else
        {
            currentState = blockCard;
            ui->mainWindow->hide();
            set_button_on();

            ui->firstWindow->setText("Enter PIN:");
            ui->PIN->setText("");
            ui->firstWindow->show();
        }


    } else if(!ui->cards->isHidden()){
        QByteArray ba = b.get_current_card().getId().toLocal8Bit();
        const char *str = ba.data();
        check_block_card(str);

    } else if(!ui->cash->isHidden()){
        give_cash(1000);
    }
}

void MainWindow::on_screen_6_clicked()
{
    if(check_block_card(b.get_current_card().getId()))
    {
        ui->mainWindow->show();
    }
    else
    {
        if(!ui->mainWindow->isHidden()){
            if(!ui->cash->isHidden()){
                bool ok;
                int res;
                do{
                    ok = true;
                    res = QInputDialog::getInt(this, tr("Choose amount (multiple of 50)"),
                                               tr(""), 0, QLineEdit::Normal);
                    if (res < 0 ){
                        QMessageBox::warning(this, tr("Error"),
                                             tr("Amount must be more than 0"));
                        ok = false;
                    } else if(res % 50 != 0){
                        ok = false;
                        QMessageBox::warning(this, tr("Error"),
                                             tr("Amount must be multiple of 50"));
                    }
                    qDebug() << res;
                } while(res < 0 || !ok);
                if(res != 0){
                    give_cash(res);
                }
            } else{
                ui->mainWindow->hide();
                set_button_on();
                currentState = changePIN;
                ui->firstWindow->setText("Enter old PIN:");
                ui->PIN->setText("");
                ui->firstWindow->show();
            }

        } else if(!ui->cards->isHidden()){
            QByteArray ba = b.get_current_card().getId().toLocal8Bit();
            const char *str = ba.data();
            check_block_card(str);

        }
    }
}

void MainWindow::on_screen_7_clicked()
{
    if(!ui->mainWindow->isHidden()){

        ui->mainWindow->close();
        ui->other->show();
    }
}

void MainWindow::on_screen_8_clicked()
{
    if(!ui->mainWindow->isHidden()){
        if(!ui->cash->isHidden()){
                ui->mainWindow->show();
                ui->cash->close();

            } else{
            set_default();
        }

    } else if(!ui->cards->isHidden()){
        ui->mainWindow->show();
        ui->cards->close();

    } else if(!ui->cash->isHidden()){
        ui->mainWindow->show();
        ui->cash->close();

    } else if(!ui->other->isHidden()){
        ui->mainWindow->show();
        ui->other->close();

    } else if(!ui->info->isHidden()){
        ui->mainWindow->show();
        ui->info->setText("");
        ui->info->close();
    }
}

void MainWindow::on_button_0_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "0");
}


void MainWindow::on_button_1_clicked()
{

    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "1");
}

void MainWindow::on_button_2_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "2");
}

void MainWindow::on_button_3_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "3");
}
void MainWindow::on_button_4_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "4");
}
void MainWindow::on_button_5_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "5");
}
void MainWindow::on_button_6_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "6");
}
void MainWindow::on_button_7_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "7");
}
void MainWindow::on_button_8_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "8");
}
void MainWindow::on_button_9_clicked()
{
    ui->firstWindow->setText(ui->firstWindow->toPlainText()+"*");
    ui->PIN->setText(ui->PIN->toPlainText() + "9");
}

void MainWindow::on_ok_clicked()
{
    switch (currentState) {
    case unauthorized:
        if(!ui->firstWindow->isHidden()) {
            if( ui->PIN->toPlainText() == b.get_current_card().getPin()){
                QMessageBox::about(this, tr("Welcome"),
                                   tr("PIN is correct"));
                set_button_off();

                ui->firstWindow->close();
                ui->mainWindow->show();

                ui->empty->close();
                currentState = authorized;
            } else{
                QMessageBox::warning(this, tr("Error"),
                                     tr("Invalid Pin"));
                if(ui->pins->text() == "3"){
                    ui->pins->setText("2");
                } else  if(ui->pins->text() == "2"){
                    ui->pins->setText("1");
                } else  {
                    QMessageBox::warning(this, tr("Error"),
                                         tr("Your card is blocked now"));
                    b.activateCard(b.get_current_card().getId(), false);

                    ui->PIN->setText("");
                    ui->firstWindow->close();
                    ui->mainWindow->close();
                    ui->insert_card->setDisabled(true);
                    ui->empty->show();

                }
            }
            ui->PIN->setText("");
            ui->firstWindow->setText("Enter PIN:\n");
        }
        break;
    case blockCard:
        if( ui->PIN->toPlainText() == b.get_current_card().getPin()){
            {
                QMessageBox msgBox;
                QString temp ("You want to block your current card ");
                temp += b.get_current_card().getId();
                msgBox.setText(temp);
                msgBox.setInformativeText("Are you sure?");
                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                msgBox.setDefaultButton(QMessageBox::Cancel);
                int ret = msgBox.exec();
                switch (ret) {
                case QMessageBox::Ok:
                    b.activateCard(b.get_current_card().getId(), false);
                    QMessageBox::warning(this, tr("Error"),
                                         tr("Your card is blocked now"));
                    set_default();

                    break;
                case QMessageBox::Cancel:
                    on_cancel_clicked();
                    break;
                default:
                    // should never be reached
                    break;
                }
            }
        } else {
            ui->firstWindow->setText("Enter PIN:");
            ui->PIN->setText("");
            QMessageBox::warning(this, tr("Error"),
                                 tr("Wrong PIN"));

        }
        break;
    case unblockCard:
        if( ui->PIN->toPlainText() == b.get_current_card().getPin()){
            {
                QMessageBox msgBox;
                QString temp ("You want to unblock your current card ");
                temp += b.get_current_card().getId();
                msgBox.setText(temp);
                msgBox.setInformativeText("Are you sure?");
                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                msgBox.setDefaultButton(QMessageBox::Cancel);
                int ret = msgBox.exec();
                switch (ret) {
                case QMessageBox::Ok:
                    b.activateCard(b.get_current_card().getId(), true);
                    QMessageBox::warning(this, tr("Error"),
                                         tr("Your card is active now"));
                    set_default();

                    break;
                case QMessageBox::Cancel:
                    on_cancel_clicked();
                    break;
                default:
                    // should never be reached
                    break;
                }
            }
        } else {
            ui->firstWindow->setText("Enter PIN:");
            ui->PIN->setText("");
            QMessageBox::warning(this, tr("Error"),
                                 tr("Wrong PIN"));

        }
        break;
    case changePIN:
        QStringList level = ui->PIN->toPlainText().split(QLatin1Char('\n'), Qt::SkipEmptyParts);

        switch (level.size()) {
        case 1:
            if( ui->PIN->toPlainText() == b.get_current_card().getPin()){
                ui->firstWindow->setText(ui->firstWindow->toPlainText()+"\nEnter new PIN:");
                ui->PIN->setText(ui->PIN->toPlainText() +"\n");
            } else {
                ui->firstWindow->setText("Enter old PIN:");
                ui->PIN->setText("");
                QMessageBox::warning(this, tr("Error"),
                                     tr("Wrong PIN"));

            }
            break;
        case 2:
            if(level.at(1).size() != 4){
                on_reset_clicked();
                QMessageBox::warning(this, tr("Error"),
                                     tr("PIN must be 4 numbers"));
            } else if(level.at(1) == level.at(0)){
                on_reset_clicked();
                QMessageBox::warning(this, tr("Error"),
                                     tr("New PIN can't be as previous"));
            } else if(level.at(1)[0] == '0') {
                on_reset_clicked();
                QMessageBox::warning(this, tr("Error"),
                                     tr("PIN can't starts with 0 value"));
            } else{
                ui->firstWindow->setText(ui->firstWindow->toPlainText()+"\nConfirm new PIN:");
                ui->PIN->setText(ui->PIN->toPlainText() +"\n");
            }

            break;
        case 3:
            if( level.at(1) == level.at(2)){
                QMessageBox msgBox;
                QString temp ("You want to change PIN on your current card ");
                temp += b.get_current_card().getId();
                msgBox.setText(temp);
                msgBox.setInformativeText("Are you sure?");
                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                msgBox.setDefaultButton(QMessageBox::Cancel);
                int ret = msgBox.exec();
                switch (ret) {
                case QMessageBox::Ok:
                    ui->PIN->setText("");
                    ui->firstWindow->setText("Enter PIN:\n");
                    ui->firstWindow->hide();
                    set_button_off();
                    ui->mainWindow->show();
                    b.change_pin(b.get_current_card().getId(), level.at(2));
                    QMessageBox::about(this, tr("PIN"),
                                       tr("PIN has changed"));
                    currentState = authorized;

                    break;
                case QMessageBox::Cancel:
                    ui->firstWindow->setText("Enter old PIN:");
                    ui->PIN->setText("");
                    break;
                default:
                    // should never be reached
                    break;
                }
            } else {
                on_reset_clicked();
                QMessageBox::warning(this, tr("Error"),
                                     tr("PIN doesn't match"));
            }
            break;
        default:
            break;
        }

        break;
    }


}
void MainWindow::on_reset_clicked()
{
    switch (currentState) {
    case unauthorized:
        if(!ui->firstWindow->isHidden()) {
            ui->PIN->setText("");
            ui->firstWindow->setText("Enter PIN:\n");
        }
        break;
    case changePIN:
        ui->firstWindow->setText("Enter old PIN:");
        ui->PIN->setText("");
        break;
    case blockCard:
        ui->firstWindow->setText("Enter PIN:");
        ui->PIN->setText("");
        break;
    }
}

void MainWindow::on_cancel_clicked()
{
    switch (currentState) {
    case unauthorized:
        if(!ui->firstWindow->isHidden()) {
            ui->PIN->setText("");
            ui->firstWindow->close();
            ui->mainWindow->close();
            ui->insert_card->setDisabled(false);
            set_button_off();
            ui->empty->show();
        }
        break;
    case changePIN:
        ui->PIN->setText("");
        ui->firstWindow->setText("Enter PIN:\n");
        ui->firstWindow->hide();
        set_button_off();
        ui->mainWindow->show();
        currentState = authorized;
        break;
    case blockCard:
        ui->PIN->setText("");
        ui->firstWindow->setText("Enter PIN:\n");
        ui->firstWindow->hide();
        set_button_off();
        ui->mainWindow->show();
        currentState = authorized;
        break;
    case unblockCard:
        ui->PIN->setText("");
        ui->firstWindow->setText("Enter PIN:\n");
        ui->firstWindow->hide();
        set_button_off();
        ui->mainWindow->show();
        currentState = authorized;
        break;
    }

}



void MainWindow::on_insert_cash_clicked()
{
    cashWidget->show();
}

void MainWindow::set_button_off()
{
    ui->button_0->setDisabled(true);
    ui->button_1->setDisabled(true);
    ui->button_2->setDisabled(true);
    ui->button_3->setDisabled(true);
    ui->button_4->setDisabled(true);
    ui->button_5->setDisabled(true);
    ui->button_6->setDisabled(true);
    ui->button_7->setDisabled(true);
    ui->button_8->setDisabled(true);
    ui->button_9->setDisabled(true);
    ui->ok->setDisabled(true);
    ui->reset->setDisabled(true);
    ui->cancel->setDisabled(true);
}

void MainWindow::set_button_on()
{
    ui->button_0->setDisabled(false);
    ui->button_1->setDisabled(false);
    ui->button_2->setDisabled(false);
    ui->button_3->setDisabled(false);
    ui->button_4->setDisabled(false);
    ui->button_5->setDisabled(false);
    ui->button_6->setDisabled(false);
    ui->button_7->setDisabled(false);
    ui->button_8->setDisabled(false);
    ui->button_9->setDisabled(false);
    ui->ok->setDisabled(false);
    ui->reset->setDisabled(false);
    ui->cancel->setDisabled(false);
}

void MainWindow::switch_off()
{
    ui->insert_card->setDisabled(true);
    ui->screen_1->setDisabled(true);
    ui->screen_2->setDisabled(true);
    ui->screen_3->setDisabled(true);
    ui->screen_4->setDisabled(true);
    ui->screen_5->setDisabled(true);
    ui->screen_6->setDisabled(true);
    ui->screen_7->setDisabled(true);
    ui->screen_8->setDisabled(true);

}

void MainWindow::switch_on()
{
    ui->insert_card->setDisabled(false);
    ui->screen_1->setDisabled(false);
    ui->screen_2->setDisabled(false);
    ui->screen_3->setDisabled(false);
    ui->screen_4->setDisabled(false);
    ui->screen_5->setDisabled(false);
    ui->screen_6->setDisabled(false);
    ui->screen_7->setDisabled(false);
    ui->screen_8->setDisabled(false);
}



void MainWindow::set_default()
{
    /*b.addAccount("Nick");
    b.addAccount("Nazar");
    b.addAccount("Artem");
    b.addAccount("Dasha");
    b.addCard("1000000000000004", "1111", 100, true, 2);
    qDebug() << b.addCard("1000000000000002", "1111", 10, true, 0);
    qDebug() << b.addCard("1000000000000002", "1111", 10, true, 0);
    qDebug() << b.addCard("1000000000000003", "1111", 10000, false, 0);
    qDebug() << b.addCard("1000000000000000", "0000", 100, true, 0);
    qDebug() << b.addCard("1000000000000001", "1234", 1000, true, 1);
    qDebug() << b.addCard("1000000000000009", "1234", 1000, false, 1);*/
    ui->info->close();
    ui->firstWindow->close();
    ui->mainWindow->close();
    ui->PIN->close();
    ui->cash->close();
    ui->settings_btn->setDisabled(false);
    ui->other->close();
    ui->cards->close();
    ui->addCash->close();
    ui->insert_cash->setDisabled(true);
    ui->PIN->close();
    ui->pins->close();
    ui->sum->close();
    ui->empty->show();
    ui->insert_card->setDisabled(false);
    ui->button_0->setDisabled(true);
    ui->button_1->setDisabled(true);
    ui->button_2->setDisabled(true);
    ui->button_3->setDisabled(true);
    ui->button_4->setDisabled(true);
    ui->button_5->setDisabled(true);
    ui->button_6->setDisabled(true);
    ui->button_7->setDisabled(true);
    ui->button_8->setDisabled(true);
    ui->button_9->setDisabled(true);
    ui->ok->setDisabled(true);
    ui->reset->setDisabled(true);
    ui->cancel->setDisabled(true);
    currentState = unauthorized;
}

bool MainWindow::check_block_card(QString a)
{
    qDebug() << b.get_all_blocked()->contains(a);
    bool foo = true;
    if (b.get_all_blocked()->contains(a)) foo = false;
    if(!foo)
    {
        QMessageBox::warning(this, tr("Error"),
                             tr("This card is blocked"));
        return true;
    } else {
        ui->mainWindow->show();
        ui->cards->close();
        return false;
    }

}

void MainWindow::give_cash(const int a)
{   if(a < 0 && (-a) > limitCashInsert){
        QMessageBox::warning(this, tr("Error"),
                             tr("Limit is exceeded"));
    }else if(a > limitCash){
        QMessageBox::warning(this, tr("Error"),
                             tr("Limit is exceeded"));
    } else if (b.get_current_card().getSum() < a){
        QMessageBox::warning(this, tr("Error"),
                             tr("Not enough money"));
    } else {
        QByteArray ba = b.get_current_card().getId().toLocal8Bit();
        const char *str = ba.data();
        b.updateSum(str,(-1) * a);
        if(a > 0){
            QString temp ("You got ");
            temp+=QString::number(a);
            temp+=" dollars";
            QMessageBox::about(this, tr("Cash"),
                               tr(temp.toUtf8().data()));
        } else {
            QString temp ("Card balance: ");
            temp += QString::number(b.get_current_card().getSum());
            QMessageBox::about(this, tr("Balance"),
                               tr(temp.toUtf8().data()));
        }

    }
}



void MainWindow::on_settings_btn_clicked()
{
    settingsWidget->show();

}




