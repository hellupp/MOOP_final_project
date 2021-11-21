#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QMessageBox>
#include <QInputDialog>
#include <QGridLayout>
#include <QSignalMapper>
#include "Bank.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *cashWidget = new QWidget;
    QWidget *settingsWidget = new QWidget;
    Bank b;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void change_sum_cash(const int);

    void settings_b_1();
    void settings_b_2();
    void settings_b_3();
    void settings_b_4();

    void on_insert_card_clicked();

    void on_screen_1_clicked();
    void on_screen_2_clicked();
    void on_screen_3_clicked();
    void on_screen_4_clicked();
    void on_screen_5_clicked();
    void on_screen_6_clicked();
    void on_screen_7_clicked();
    void on_screen_8_clicked();


    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();


    void on_reset_clicked();
    void on_ok_clicked();
    void on_cancel_clicked();



    void on_insert_cash_clicked();
    void on_settings_btn_clicked();
    void on_button_0_clicked();


private:
    static QString getHex(QWidget *parent,
                          const QString &title,
                          const QString &label,
                          int value = 0,
                          int min = -2147483647,
                          int max = 2147483647,
                          int step = 1,
                          bool *ok = Q_NULLPTR,
                          Qt::WindowFlags flags = Qt::WindowFlags()){
        QInputDialog dialog(parent, flags);
        dialog.setWindowTitle(title);
        dialog.setLabelText(label);
        dialog.setIntRange(min, max);
        dialog.setIntValue(value);
        dialog.setIntStep(step);
        QSpinBox *spinbox = dialog.findChild<QSpinBox*>();
        spinbox->setDisplayIntegerBase(16);

        bool ret = dialog.exec() == QDialog::Accepted;
        if (ok)
            *ok = ret;
        return spinbox->text();
    }

    enum States
    {
        changePIN, // присваивается 0
        authorized,
        unauthorized, // присваивается 1
        blockCard, // присваивается 2
        unblockCard
    };

    States currentState = unauthorized;

    int limitCash = 1000;

    int limitCashInsert = 500;

    bool working = true;

    void set_button_off();

    void set_button_on();

    void switch_off();

    void switch_on();

    void set_default();

    bool check_block_card(QString a);

    void give_cash(const int);



    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
