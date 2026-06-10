#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>

class MyComboBox : public QComboBox
{
    Q_OBJECT

signals:
    void aboutToPopup();

public:
    using QComboBox::QComboBox;


protected:
    void showPopup() override {
        emit aboutToPopup();
        QComboBox::showPopup();
    }

};

#endif // MYCOMBOBOX_H
