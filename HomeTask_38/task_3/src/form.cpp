#include "form.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>


Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);

  connect(pushButton, &QPushButton::clicked, [this]()
  {
    QString pathToFile = QFileDialog::getOpenFileName(nullptr, tr("Open Image"),
                                                      "./", tr("images (*.jpg);;all (*)"));
    if (pathToFile.isEmpty()) {
      imageLabel->setText("image not loaded");
      return;
    }
    sourceImage.load(pathToFile);
    imageLabel->setPixmap(QPixmap::fromImage(sourceImage));
  });

  connect(horizontalSlider, &QSlider::valueChanged, [this](int newValue)
  {
    QFuture<QImage> handler = QtConcurrent::run(blurImage, newValue, sourceImage);
    handler.waitForFinished();

    imageLabel->setPixmap(QPixmap::fromImage(handler.result()
                          .scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio)));
  });
}

Form::~Form()
{ }

QImage blurImage(int blurRadius, QImage source)
{
  if (source.isNull()) { return QImage(); }

  QGraphicsScene scene;
  QGraphicsPixmapItem item;
  item.setPixmap(QPixmap::fromImage(source));

  auto *blur = new QGraphicsBlurEffect;
  blur->setBlurRadius(blurRadius);
  item.setGraphicsEffect(blur);
  scene.addItem(&item);
  QImage result(source.size(), QImage::Format_ARGB32);
  result.fill(Qt::transparent);
  QPainter painter(&result);
  scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));

  return result;
}

