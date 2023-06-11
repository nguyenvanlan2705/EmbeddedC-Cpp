#include "widget.h"
#include "ui_widget.h"
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setFixedSize(400,400);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupUi()
{
    //declare Lable
    QFont textFont("Times", 10, QFont::Bold);
    QLabel *myLabel = new QLabel(this);
    myLabel->setMinimumSize(200,100);
    myLabel->setFont(textFont);
    myLabel->move(100,25);

    //declare TextEdit
    QTextEdit *myText = new QTextEdit(this);
    myText->move(70, 55);

    //connect to signal
    connect(myText, &QTextEdit::textChanged, [=](){
        qDebug()<<"Text Change";
    });

    /* copy
     * paste
     * undo
     * redu
     * setHtml
     * setPlainText
     * */
    // copy , cut, and paste
    QPushButton *copyButt= new QPushButton("Copy", this);
    copyButt -> setMinimumSize(50,25);
    copyButt -> move(10, 250);
    connect(copyButt, &QPushButton::clicked, [=](){
        myText->copy();
    });

    QPushButton *cutButt= new QPushButton("Cut", this);
    cutButt -> setMinimumSize(50,25);
    cutButt -> move(110, 250);
    connect(cutButt, &QPushButton::clicked, [=](){
        myText->cut();
    });

    QPushButton *pasteButt= new QPushButton("Paste", this);
    pasteButt -> setMinimumSize(50,25);
    pasteButt -> move(210, 250);
    connect(pasteButt, &QPushButton::clicked, [=](){
        myText->paste();
    });

    //undo & redo
    QPushButton *reduButt= new QPushButton("Redu", this);
    reduButt -> setMinimumSize(50,25);
    reduButt -> move(10, 280);
    connect(reduButt, &QPushButton::clicked, [=](){
        myText->redo();
    });

    QPushButton *undoButt= new QPushButton("Undo", this);
    undoButt -> setMinimumSize(50,25);
    undoButt -> move(110, 280);
    connect(undoButt, &QPushButton::clicked, [=](){
        myText->undo();
    });

    //Set Plain text and html to the text edit
    QPushButton *plainTextButt= new QPushButton("Plain Text", this);
    plainTextButt->setMinimumSize(100,25);
    plainTextButt-> move(10,310);
    connect(plainTextButt, &QPushButton::clicked, [=](){
        myText->setPlainText("Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?");
    });

    QPushButton *htmlButt= new QPushButton("Html", this);
    htmlButt->setMinimumSize(100,25);
    htmlButt-> move(120,310);
    connect(htmlButt, &QPushButton::clicked, [=](){
        myText->setHtml("<h1>Kigali Districts</h1><p>The city of Kigali has three districts : </br> <ul> <li>Gasabo</li> <li>Nyarugenge</li><li>Kicukiro</li></ul></p>");
    });
    //Grab text and html
    QPushButton * grabTextButton = new QPushButton("Grab Text",this);
    grabTextButton->setMinimumSize(100,24);
    grabTextButton->move(10,340);
    connect(grabTextButton,&QPushButton::clicked,[=](){
        qDebug() << "The plain text inside the text edit is : " << myText->toPlainText();
    });

    QPushButton * grabHtmlButton = new QPushButton("GrabHtml",this);
    grabHtmlButton->setMinimumSize(100,25);
    grabHtmlButton->move(120,340);
    connect(grabHtmlButton,&QPushButton::clicked,[=](){
        qDebug() << "The html inside the text edit is : " << myText->toHtml();
    });

}

