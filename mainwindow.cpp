#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),
            this,SLOT(on_pushButton_clicked()));

    connect(ui->pushButton_2,SIGNAL(clicked(bool)),
            this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString flights[] = {"f1", "f2", "f3"};
    int seats[] = {2, 34, 0};

    QString uFlight = ui->lineEdit->text();
    QString uName = ui->lineEdit_2->text();

    bool found = false;

    // Correctly iterate over the array
    for (int i = 0; i < sizeof(flights) / sizeof(flights[0]); i++)
    {
        if (uFlight == flights[i] && seats[i] > 0)
        {
            QMessageBox::information(this, "Success Message",
                                     "User Name: " + uName + "\n"
                                                             "Flight: " + flights[i] + "\n"
                                                        "Reserved Seat Successfully :)");
            found = true;
            break;
        }
    }

    // Show error message if not found
    if (!found)
    {
        QMessageBox::information(this, "Error Message", "Incorrect Flight Number or Seat not available!");
    }
}
