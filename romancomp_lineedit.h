#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <iostream>
#include <QCompleter>
#include <QStandardItem>


class RomanCompLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	explicit RomanCompLineEdit(QWidget *parent = 0);
	void setModel(QAbstractItemModel *model) { c.setModel(model); }
	
signals:
	
public slots:
	void prefixToKatakana (const QString &completionPrefix) ;

private:
	QCompleter c;
	QStandardItemModel item_model;
	QString romanToKatakana (const QString &roman) const;
};

#endif // MYLINEEDIT_H
