/**
 * @file glwidget.h
 * @brief Этот файл содержит объявление класса GLWidget, который отвечает за
 * рендеринг 3D-графики с использованием OpenGL в приложении на основе Qt.
 *
 * Класс GLWidget наследует от QOpenGLWidget и реализует методы для
 * инициализации OpenGL, обработки изменения размера окна и отрисовки сцены.
 * Также он содержит свойства для настройки различных параметров визуализации,
 * таких как цвет линий, цвет фона и другие.
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QPoint>

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

extern "C" {
#include "affine_transformations.h"
#include "parser.h"
}

/**
 * @struct Properties
 * @brief Структура для хранения свойств визуализации.
 *
 * Структура Properties содержит параметры, которые управляют рендерингом,
 * такие как тип проекции, тип линий, цвет линий и точек, ширина линий,
 * размер точек и цвет фона. Эти параметры могут быть настроены пользователем
 * для изменения внешнего вида 3D-сцены.
 */
struct Properties {
  int projection_type;  ///< Тип проекции (например, ортографическая или
                        ///< перспективная).
  int line_type;  ///< Тип линий (например, сплошные или пунктирные).
  float line_color[3];  ///< Цвет линий в формате RGB.
  float line_width;     ///< Ширина линий.
  int point_type;  ///< Тип точек (например, круги или квадраты).
  float point_color[3];  ///< Цвет точек в формате RGB.
  float point_size;      ///< Размер точек.
  float back_color[3];   ///< Цвет фона в формате RGB.
  double scene;          ///< Параметры сцены.
};

/**
 * @class GLWidget
 * @brief Класс для рендеринга 3D-графики с использованием OpenGL.
 *
 * Класс GLWidget отвечает за инициализацию OpenGL, изменение размера окна
 * и отрисовку 3D-сцены. Он также содержит модель, которую необходимо
 * отобразить, и свойства, управляющие рендерингом. Класс реализует основные
 * функции, необходимые для работы с OpenGL в приложениях на Qt.
 */
class GLWidget : public QOpenGLWidget {
 protected:
  void initializeGL() override;  ///< Инициализация OpenGL.
  void resizeGL(int w, int h) override;  ///< Обработка изменения размера окна.
  void paintGL() override;  ///< Отрисовка сцены.

 public:
  Model model = {nullptr, nullptr, 0,
                 0,       {0.0},   {0.0}};  ///< Модель для отображения.
  Properties property = {0,   0xFFFF, {0.9, 0.7, 0.2}, 1.0, 0, {1, 1, 1}, 1.0,
                         {0}, 0};  ///< Свойства визуализации.

  GLWidget(QWidget* parent = nullptr);  ///< Конструктор класса.
  ~GLWidget();                          ///< Деструктор класса.

  void centering();  ///< Центрирует сцену.
};

#endif  // GLWIDGET_H
