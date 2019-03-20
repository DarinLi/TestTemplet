#ifndef MAINTITLEBARUI_H
#define MAINTITLEBARUI_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>

#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QToolButton>
#include <QButtonGroup>
#include <QHBoxLayout>

class MainTitleBarUI : public QWidget
{
    Q_OBJECT

public:
    explicit MainTitleBarUI(QWidget *parent = nullptr);
    ~MainTitleBarUI() override;

public:
    void titleBarCustomCreate(void);
    void titleBarMenuSettingsCreate(void);

public:
    void setWindowTitle(const QString &title);
    QString WindowTitle() const;

    void setWindowIcon(const QPixmap &icon);
    QPixmap icon() const;

    void setTitleBarHeight(const int height);
    int titleBarHeight() const;

    QButtonGroup* titleBarButtonGroup();
    QToolButton* mainMaxButton();
    QAction* qAPPAboutButton();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    class MainTitleBarUIPrivate;
    const QScopedPointer<MainTitleBarUIPrivate> d;
};

#endif // MAINWIDGETUI_H
