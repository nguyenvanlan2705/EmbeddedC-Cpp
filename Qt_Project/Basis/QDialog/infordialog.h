#ifndef INFORDIALOG_H
#define INFORDIALOG_H

#include <QDialog>

namespace Ui {
class InforDialog;
}

class InforDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InforDialog(QWidget *parent = nullptr);
    ~InforDialog();

    QString getPosition() const;

    QString getFavoriteOs() const;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    QString position;
    QString favoriteOs;
    Ui::InforDialog *ui;
};

#endif // INFORDIALOG_H
