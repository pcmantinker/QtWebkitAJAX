#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_page = ui->webView->page();
    m_nam = new QNetworkAccessManager();

    m_page->setNetworkAccessManager(m_nam);
    m_page->networkAccessManager();

    connect(m_nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    QFile file;
    file.setFileName(":/js/jquery-2.1.1.min.js");
    file.open(QIODevice::ReadOnly);
    m_jQuery = file.readAll();
    file.close();

    ui->webView->load(QUrl("about:blank"));
    QWebFrame *frame = m_page->mainFrame();


    frame->evaluateJavaScript(m_jQuery);

    frame->evaluateJavaScript("$(document).ready(function() { alert('jQuery loaded!'); });");

    frame->evaluateJavaScript("$.ajax({"
                              "url: 'http://www.json-generator.com/api/json/get/cqkXBAEoQy?indent=2',"
                              "method: 'GET',"
                              "dataType: 'json'"
                          "}).done(function (data) {"
                              "for (var i = 0; i < data.length; i++) {"
                                  "alert(data[i].name);"
                              "}"
                          "}).error(function (data) { alert('AJAX error'); });");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    QString replyUrl = reply->url().toString();
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << statusCode;
    qDebug() << replyUrl;
    qDebug() << str;
}
