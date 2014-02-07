#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QStandardItem>
#include <QCompleter>

#include "romancomp_lineedit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    QStandardItemModel item_model;
    QCompleter completer;
    QLineEdit line_edit;
    Ui::MainWindow *ui;
		RomanCompLineEdit *my_lineedit;
};

#endif // MAINWINDOW_H
