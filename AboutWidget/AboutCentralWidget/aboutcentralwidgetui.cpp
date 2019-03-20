#include "aboutcentralwidgetui.h"
#include "ui_aboutcentralwidgetui.h"

AboutCentralWidgetUI::AboutCentralWidgetUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutCentralWidgetUI)
{
    ui->setupUi(this);
}

AboutCentralWidgetUI::~AboutCentralWidgetUI()
{
    delete ui;
}

void AboutCentralWidgetUI::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
