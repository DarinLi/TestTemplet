#include "maincentralwidgetui.h"
#include "ui_maincentralwidgetui.h"

MainCentralWidgetUI::MainCentralWidgetUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainCentralWidgetUI)
{
    ui->setupUi(this);
}

MainCentralWidgetUI::~MainCentralWidgetUI()
{
    delete ui;
}

void MainCentralWidgetUI::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
