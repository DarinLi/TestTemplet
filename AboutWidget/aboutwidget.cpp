#include "aboutwidget.h"

class AboutWidget::AboutWidgetPrivate
{
public:
    QVBoxLayout *layout = nullptr;
    AboutTitleBarUI *m_pAboutTitleBarUI = nullptr;
    AboutCentralWidgetUI *m_pAboutCentralWidgetUI = nullptr;
};

AboutWidget::AboutWidget(QWidget *parent) :
    QDialog(parent),
    d(new AboutWidgetPrivate)
{
    setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    setObjectName(QStringLiteral("MainWidget"));

    frameLessWidget.activateOn(this);

    d->layout = new QVBoxLayout(this);
    d->layout->setSpacing(0);
    d->layout->setMargin(0);

    d->m_pAboutTitleBarUI = new AboutTitleBarUI();

    frameLessWidget.setTitleHeight(d->m_pAboutTitleBarUI->titleBarHeight());

    d->m_pAboutTitleBarUI->setWindowTitle(QStringLiteral("About"));
    d->m_pAboutTitleBarUI->setWindowIcon(QPixmap("./logo/logo.ico"));

    connect(d->m_pAboutTitleBarUI->titleBarButtonGroup(),
            QOverload<int>::of(&QButtonGroup::buttonClicked),
            this, &AboutWidget::mainTitleBarButtonClicked);

    d->layout->addWidget(d->m_pAboutTitleBarUI);
    d->layout->addWidget(d->m_pAboutCentralWidgetUI = new AboutCentralWidgetUI);

    setFixedSize(d->m_pAboutCentralWidgetUI->width(),
                 d->m_pAboutCentralWidgetUI->height() + d->m_pAboutTitleBarUI->titleBarHeight());

    setMinimumHeight(d->m_pAboutTitleBarUI->titleBarHeight() + 30);
}

AboutWidget::~AboutWidget()
{

}

void AboutWidget::mainTitleBarButtonClicked(int id)
{
    if (id == 2) {
        this->close();
    }
}

void AboutWidget::setFixedSize(const QSize &size)
{
    resize(size);
    frameLessWidget.setWidgetResizable(false);
}

void AboutWidget::setFixedSize(int w, int h)
{
    resize(w, h);
    frameLessWidget.setWidgetResizable(false);
}
