#ifndef SFMLWIDGET_H
#define SFMLWIDGET_H

#include <QWidget>
#include <QResizeEvent>

#include <SFML/Graphics.hpp>

class SFMLWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SFMLWidget(QWidget *parent = nullptr);
    void handleEvents();
    void update();
    void draw();

private:
    QPaintEngine *paintEngine() const;
    void showEvent(QShowEvent*) override;
    void enterEvent(QEvent *event) override;
    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent *event) override;

    sf::RenderWindow m_window;
    sf::CircleShape  m_circle;
};

#endif // SFMLWIDGET_H
