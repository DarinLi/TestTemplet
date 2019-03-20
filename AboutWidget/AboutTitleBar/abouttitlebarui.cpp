#include "abouttitlebarui.h"

class AboutTitleBarUI::AboutTitleBarUIPrivate
{
public:
    QHBoxLayout *titleBarLayout = nullptr;

    QLabel *iconLabel = nullptr;
    QLabel *titleLabel = nullptr;

    QToolButton* closeButton = nullptr;

    QButtonGroup *m_pButtonGroup = nullptr;

    qint32 titleBarHeight = 30;
};

AboutTitleBarUI::AboutTitleBarUI(QWidget *parent) :
    QWidget(parent),
    d(new AboutTitleBarUIPrivate)
{
    this->setObjectName(QString::fromUtf8("AboutTitleBar"));
    this->setAutoFillBackground(true);
    this->setFixedHeight(d->titleBarHeight);

    d->titleBarLayout = new QHBoxLayout(this);
    d->titleBarLayout->setContentsMargins(QMargins(5, 0, 5, 0));
    d->titleBarLayout->setSpacing(0);

    titleBarCustomCreate();

    d->m_pButtonGroup = new QButtonGroup(this);
    d->m_pButtonGroup->setExclusive(true);

    d->m_pButtonGroup->addButton(d->closeButton, 2);
}

AboutTitleBarUI::~AboutTitleBarUI()
{

}

void AboutTitleBarUI::titleBarCustomCreate(void)
{
    /*************iconLabel*****************/
    d->titleBarLayout->addWidget(d->iconLabel = new QLabel);
    d->iconLabel->setScaledContents(true);
    d->iconLabel->setFixedSize(16, 16);

    d->titleBarLayout->addSpacing(8);

    /*************titleLabel*****************/
    d->titleBarLayout->addWidget(d->titleLabel = new QLabel, 2);
    d->titleLabel->setObjectName(QStringLiteral("titlelabel"));

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

void AboutTitleBarUI::setTitleBarHeight(const int height)
{
    d->titleBarHeight = height;
}

int AboutTitleBarUI::titleBarHeight() const
{
    return d->titleBarHeight;
}

void AboutTitleBarUI::setWindowTitle(const QString &title)
{
    d->titleLabel->setText(title);
}

QString AboutTitleBarUI::WindowTitle() const
{
    return d->titleLabel->text();
}

void AboutTitleBarUI::setWindowIcon(const QPixmap &icon)
{
    d->iconLabel->setPixmap(icon);
}

QPixmap AboutTitleBarUI::icon() const
{
    return *d->iconLabel->pixmap();
}

QButtonGroup* AboutTitleBarUI::titleBarButtonGroup()
{
    return d->m_pButtonGroup;
}

void AboutTitleBarUI::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
