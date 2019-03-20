#ifndef MAINCENTRALWIDGETUI_H
#define MAINCENTRALWIDGETUI_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class MainCentralWidgetUI;
}

class MainCentralWidgetUI : public QWidget
{
    Q_OBJECT

public:
    explicit MainCentralWidgetUI(QWidget *parent = nullptr);
    ~MainCentralWidgetUI() override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainCentralWidgetUI *ui;
};

#endif // MAINCENTRALWIDGETUI_H
