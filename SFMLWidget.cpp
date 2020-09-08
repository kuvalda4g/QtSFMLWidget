#include "sfmlwidget.h"

SFMLWidget::SFMLWidget(QWidget *parent) : QWidget(parent), m_circle(100)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);
}

void SFMLWidget::showEvent(QShowEvent*)
{
    m_window.create(reinterpret_cast<sf::WindowHandle>(winId()));
    m_circle.setFillColor(sf::Color::Yellow);
}

QPaintEngine *SFMLWidget::paintEngine() const
{
    return nullptr;
}

void SFMLWidget::enterEvent(QEvent*)
{
    setFocus();
}

void SFMLWidget::paintEvent(QPaintEvent*)
{
    draw();
}

void SFMLWidget::resizeEvent(QResizeEvent *event)
{
    // update the view to the new size of the window
    //m_window.setView(sf::View(sf::FloatRect(0, 0, event->size().width(), event->size().height())));

    this->handleEvents();
}

void SFMLWidget::handleEvents()
{
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            // update the view to the new size of the window
            m_window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        }
    }
}

void SFMLWidget::update()
{
    // update all the things
}

void SFMLWidget::draw()
{
    m_window.clear(sf::Color::Black);
    m_window.draw(m_circle);
    m_window.display();
}
