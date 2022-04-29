/*

<!DOCTYPE HTML>
<meta charset="utf-8">
<title>Крошечный документ HTML5</title>
<p>Дадим встряску браузеру в стиле HTML5!</p>

*/

#include "form.h"

Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);

  QTextDocument *doc;
  doc = plainTextEdit->document();
  connect(doc, &QTextDocument::contentsChanged, webEngineView, [this, doc](){ webEngineView->setHtml(doc->toPlainText()); });
}

Form::~Form()
{ }
