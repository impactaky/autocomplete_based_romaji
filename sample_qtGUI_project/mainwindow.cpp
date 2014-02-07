#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "romancomp_lineedit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("ネズミ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("ウシ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("トラ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("ウサギ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("タツ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("ヘビ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("ウマ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("ヒツジ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("サル"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("トリ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("イヌ"));
		item_model.setItem(item_model.rowCount(), 0, new QStandardItem("イノシシ"));

		my_lineedit = new RomanCompLineEdit();
		my_lineedit->setModel(&item_model);

		ui->comboBox->setModel(&item_model);
		ui->comboBox->setLineEdit(my_lineedit);
		ui->comboBox->setCompleter(0);
		ui->comboBox->lineEdit()->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}
