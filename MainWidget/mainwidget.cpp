#include "mainwidget.h"

class MainWidget::MainWidgetPrivate
{
public:
    QVBoxLayout *layout = nullptr;
    MainTitleBarUI *m_pMainTitleBarUI = nullptr;
    MainCentralWidgetUI *m_pMainCentralWidgetUI = nullptr;

    AboutWidget *m_pAboutWidget = nullptr;
};

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    d(new MainWidgetPrivate)
{
    setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    setObjectName(QStringLiteral("MainWidget"));

    frameLessWidget.activateOn(this);

    d->layout = new QVBoxLayout(this);
    d->layout->setSpacing(0);
    d->layout->setMargin(0);

    d->m_pMainTitleBarUI = new MainTitleBarUI();

    frameLessWidget.setTitleHeight(d->m_pMainTitleBarUI->titleBarHeight());

    QString title = QStringLiteral("Test ") + APPVersions +
                    QStringLiteral(" ") + APPRunStatus +
                    QStringLiteral(" By DarinLi");
    d->m_pMainTitleBarUI->setWindowTitle(title);
    d->m_pMainTitleBarUI->setWindowIcon(QPixmap("./logo/logo.ico"));

    connect(d->m_pMainTitleBarUI->titleBarButtonGroup(),
            QOverload<int>::of(&QButtonGroup::buttonClicked),
            this, &MainWidget::mainTitleBarButtonClicked);

    connect(d->m_pMainTitleBarUI->qAPPAboutButton(),
            &QAction::triggered,
            this, &MainWidget::openAboutUI);

    d->layout->addWidget(d->m_pMainTitleBarUI);
    d->layout->addWidget(d->m_pMainCentralWidgetUI = new MainCentralWidgetUI);

    resize(d->m_pMainCentralWidgetUI->width(),
           d->m_pMainCentralWidgetUI->height() + d->m_pMainTitleBarUI->titleBarHeight());

    setStyleSheet();

    setMinimumHeight(d->m_pMainTitleBarUI->titleBarHeight() + 30);
}

MainWidget::~MainWidget()
{

}

void MainWidget::mainTitleBarButtonClicked(int id)
{
    if(id == 0) {
        this->showMinimized();
    } else if(id == 1) {
        if (this->isMaximized())
            this->showNormal();
        else
            this->showMaximized();
    } else if (id == 2) {
        this->close();
    }
}

void MainWidget::openAboutUI(void)
{
    d->m_pAboutWidget = new AboutWidget(this);
    d->m_pAboutWidget->setAttribute(Qt::WA_DeleteOnClose);
    if(d->m_pAboutWidget != nullptr)
        d->m_pAboutWidget->exec();
}

bool MainWidget::event(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        if (this->isMaximized())
            d->m_pMainTitleBarUI->mainMaxButton()->setText(QChar(0xf2d2));
        else
            d->m_pMainTitleBarUI->mainMaxButton()->setText(QChar(0xf2d0));
    }

    return QWidget::event(event);
}

void MainWidget::setFixedSize(const QSize &size)
{
    resize(size);
    frameLessWidget.setWidgetResizable(false);
}

void MainWidget::setFixedSize(int w, int h)
{
    resize(w, h);
    frameLessWidget.setWidgetResizable(false);
}

void MainWidget::setStyleSheet(const QString &stytle)
{
    QFile file(stytle);

    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1Literal(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
    }
}
