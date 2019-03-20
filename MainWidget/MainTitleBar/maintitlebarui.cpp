#include "maintitlebarui.h"

class MainTitleBarUI::MainTitleBarUIPrivate
{
public:
    QHBoxLayout *titleBarLayout = nullptr;

    QLabel *iconLabel = nullptr;
    QLabel *titleLabel = nullptr;

    QToolButton* menuButton = nullptr;
    QToolButton* minButton = nullptr;
    QToolButton* maxButton = nullptr;
    QToolButton* closeButton = nullptr;

    QAction *qAPPAbout = nullptr;
    QMenu *Titlemenu = nullptr;
    QMenu *themeMenu = nullptr;

    QButtonGroup *m_pButtonGroup = nullptr;

    qint32 titleBarHeight = 30;
};

MainTitleBarUI::MainTitleBarUI(QWidget *parent) :
    QWidget(parent),
    d(new MainTitleBarUIPrivate)
{
    this->setObjectName(QString::fromUtf8("MainTitleBar"));
    this->setAutoFillBackground(true);
    this->setFixedHeight(d->titleBarHeight);

    d->titleBarLayout = new QHBoxLayout(this);
    d->titleBarLayout->setContentsMargins(QMargins(5, 0, 5, 0));
    d->titleBarLayout->setSpacing(0);

    titleBarCustomCreate();
    titleBarMenuSettingsCreate();

    d->m_pButtonGroup = new QButtonGroup(this);
    d->m_pButtonGroup->setExclusive(true);

    d->m_pButtonGroup->addButton(d->minButton, 0);
    d->m_pButtonGroup->addButton(d->maxButton, 1);
    d->m_pButtonGroup->addButton(d->closeButton, 2);
}

MainTitleBarUI::~MainTitleBarUI()
{

}

void MainTitleBarUI::titleBarCustomCreate(void)
{
    /*************iconLabel*****************/
    d->titleBarLayout->addWidget(d->iconLabel = new QLabel);
    d->iconLabel->setScaledContents(true);
    d->iconLabel->setFixedSize(16, 16);

    d->titleBarLayout->addSpacing(8);

    /*************titleLabel*****************/
    d->titleBarLayout->addWidget(d->titleLabel = new QLabel, 2);
    d->titleLabel->setObjectName(QStringLiteral("titlelabel"));

    /*************menuButton*****************/
    d->titleBarLayout->addWidget(d->menuButton = new QToolButton);
    d->menuButton->setObjectName(QStringLiteral("menubutton"));
    d->menuButton->setAutoRaise(true);
    d->menuButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    auto font = d->menuButton->font();
    font.setFamily("FontAwesome");
    font.setPixelSize(14);
    d->menuButton->setFont(font);
    d->menuButton->setText(QChar(0xf0c9));

    /*************minButton*****************/
    d->titleBarLayout->addWidget(d->minButton = new QToolButton);
    d->minButton->setObjectName(QStringLiteral("minbutton"));
    d->minButton->setAutoRaise(true);
    d->minButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    auto font1 = d->minButton->font();
    font1.setFamily("FontAwesome");
    font1.setPixelSize(12);
    d->minButton->setFont(font1);
    d->minButton->setText(QChar(0xf2d1));

    /*************maxButton*****************/
    d->titleBarLayout->addWidget(d->maxButton = new QToolButton);
    d->maxButton->setObjectName(QStringLiteral("maxbutton"));
    d->maxButton->setAutoRaise(true);
    d->maxButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    auto font3 = d->maxButton->font();
    font3.setFamily("FontAwesome");
    font3.setPixelSize(12);
    d->maxButton->setFont(font3);
    d->maxButton->setText(QChar(0xf2d0));

    /*************closeButton*****************/
    d->titleBarLayout->addWidget(d->closeButton = new QToolButton);
    d->closeButton->setObjectName(QStringLiteral("closebutton"));
    d->closeButton->setAutoRaise(true);
    d->closeButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    auto font2 = d->closeButton->font();
    font2.setFamily("FontAwesome");
    font2.setPixelSize(16);
    d->closeButton->setFont(font2);
    d->closeButton->setText(QChar(0xf00d));
}

void MainTitleBarUI::titleBarMenuSettingsCreate(void)
{
    d->qAPPAbout = new QAction(QStringLiteral("关于"));
    d->qAPPAbout->setObjectName(QStringLiteral("qAPPabout"));

    d->Titlemenu = new QMenu();
    d->Titlemenu->addAction(d->qAPPAbout);

    d->menuButton->setMenu(d->Titlemenu);
    d->menuButton->setPopupMode(QToolButton::InstantPopup);
}

void MainTitleBarUI::setTitleBarHeight(const int height)
{
    d->titleBarHeight = height;
}

int MainTitleBarUI::titleBarHeight() const
{
    return d->titleBarHeight;
}

void MainTitleBarUI::setWindowTitle(const QString &title)
{
    d->titleLabel->setText(title);
}

QString MainTitleBarUI::WindowTitle() const
{
    return d->titleLabel->text();
}

void MainTitleBarUI::setWindowIcon(const QPixmap &icon)
{
    d->iconLabel->setPixmap(icon);
}

QPixmap MainTitleBarUI::icon() const
{
    return *d->iconLabel->pixmap();
}

QButtonGroup* MainTitleBarUI::titleBarButtonGroup()
{
    return d->m_pButtonGroup;
}

QToolButton* MainTitleBarUI::mainMaxButton()
{
    return d->maxButton;
}

QAction* MainTitleBarUI::qAPPAboutButton()
{
    return d->qAPPAbout;
}

void MainTitleBarUI::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
