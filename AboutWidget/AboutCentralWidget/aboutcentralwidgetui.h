#ifndef ABOUTCENTRALWIDGETUI_H
#define ABOUTCENTRALWIDGETUI_H

#include <QDialog>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class AboutCentralWidgetUI;
}

class AboutCentralWidgetUI : public QDialog
{
    Q_OBJECT

public:
    explicit AboutCentralWidgetUI(QWidget *parent = nullptr);
    ~AboutCentralWidgetUI() override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::AboutCentralWidgetUI *ui;
};

#endif // MAINCENTRALWIDGETUI_H
