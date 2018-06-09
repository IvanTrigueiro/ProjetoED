#include "estruturadedados.h"
#include "ui_estruturadedados.h"

QList <int> ListaEncadeada;
unsigned int nElementosLSE = 0;

QStack <int> Pilha;
unsigned int nElementosPilha = 0;

QStack <int> Fila;
unsigned int nElementosFila = 0;

binarysearchtree BST;
unsigned int nElementosArv = 0;


EstruturadeDados::EstruturadeDados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EstruturadeDados)
{
    ui->setupUi(this);

}
EstruturadeDados::~EstruturadeDados()
{
    delete ui;
}

void EstruturadeDados::on_listaEnc_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void EstruturadeDados::on_pilha_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void EstruturadeDados::on_fila_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void EstruturadeDados::on_voltar1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void EstruturadeDados::on_voltar2_clicked()
{
    for(int i = nElementosLSE; i > 0; i--){
    QPushButton *botao = listaBotoes.last();
    listaBotoes.removeLast();
    delete botao;
    nElementosLSE--;
    ui->nElementos->setText(QString::number(nElementosLSE));
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void EstruturadeDados::on_voltar3_clicked()
{
    for(int i = nElementosPilha; i > 0; i--){
    QPushButton *botao = listaBotoes.last();
    listaBotoes.removeLast();
    delete botao;
    nElementosPilha--;
    ui->nElemPilha->setText(QString::number(nElementosPilha));
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void EstruturadeDados::on_voltar4_clicked()
{
    for(int i = nElementosFila; i > 0; i--){
    QPushButton *botao = listaBotoes.last();
    listaBotoes.removeLast();
    delete botao;
    nElementosFila--;

    }
    ui->nElemFila->setText(QString::number(nElementosFila));
    ui->stackedWidget->setCurrentIndex(0);
}

void EstruturadeDados::recombinarBotoesListaEnc()
{
    tamanhoBotao = 25;
    escala = 25;
    eixoX = 120;
    eixoY = 150;
    int nBotoes = listaBotoes.size();
    float anguloUnidades = (45 / nBotoes);

    for(int i = 0; i < nBotoes; i++)
    {
        QPushButton *botao = listaBotoes.at(i);
        QPropertyAnimation *animation = new QPropertyAnimation(botao, "geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF((i * escala + eixoX),
                                      (sin(anguloUnidades*i*0) * escala + eixoY),
                                      tamanhoBotao,
                                      tamanhoBotao));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void EstruturadeDados::on_inserirInicio_clicked()
{
    bool ok;
        long int inteiro = ui->lineElemento->text().toLong(&ok);

        if(inteiro == 0){
            QMessageBox::warning(this,tr("Erro!"),tr("Digite um número!"));
        } else{
            QPushButton *botao = new QPushButton(this);
            botao->setStyleSheet("font: 11pt ""Times New Roman"";"
                                 "border-width: 1px;"
                                 "border-style: solid;"
                                 "border-radius: 6px;"
                                 "border-color: black;"
                                 "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 21, 21, 255));");
            botao->setText(QString::number(inteiro));
            botao->setGeometry(ui->inserirPilha->geometry());
            botao->show();
            listaBotoes.prepend(botao);

            ListaEncadeada.prepend(inteiro);
            nElementosLSE++;
            ui->nElementos->setText(QString::number(nElementosLSE));

            recombinarBotoesListaEnc();
        }

}

void EstruturadeDados::on_inserirFim_clicked()
{
    bool ok;
        long int inteiro = ui->lineElemento->text().toLong(&ok);

        if(inteiro == 0){
            QMessageBox::warning(this,tr("Erro!"),tr("Digite um número!"));
        } else{
            QPushButton *botao = new QPushButton(this);
            botao->setStyleSheet("font: 11pt ""Times New Roman"";"
                                 "border-width: 1px;"
                                 "border-style: solid;"
                                 "border-radius: 6px;"
                                 "border-color: black;"
                                 "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 21, 21, 255));");
            botao->setText(QString::number(inteiro));
            botao->setGeometry(ui->inserirPilha->geometry());
            botao->show();
            listaBotoes.append(botao);

            ListaEncadeada.append(inteiro);
            nElementosLSE++;
            ui->nElementos->setText(QString::number(nElementosLSE));

            recombinarBotoesListaEnc();
        }
}

void EstruturadeDados::on_inserirMeio_clicked()
{
        bool ok;
        unsigned long int pos = ui->linePosicao->text().toLong(&ok);
        long int inteiro = ui->lineElemento->text().toLong(&ok);
        if(inteiro == 0){
            QMessageBox::warning(this,tr("Erro!"),tr("Digite um número!"));
        }else if(pos > nElementosLSE) {
            QMessageBox::warning(this,tr("Erro!"),tr("Posição Inválida!"));
        } else{
            QPushButton *botao = new QPushButton(this);
            botao->setStyleSheet("font: 11pt ""Times New Roman"";"
                                 "border-width: 1px;"
                                 "border-style: solid;"
                                 "border-radius: 6px;"
                                 "border-color: black;"
                                 "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 21, 21, 255));");
            botao->setText(QString::number(inteiro));
            botao->setGeometry(ui->inserirPilha->geometry());
            botao->show();
            listaBotoes.insert(pos-1 ,botao);

            ListaEncadeada.insert(pos-1, inteiro);
            nElementosLSE++;
            ui->nElementos->setText(QString::number(nElementosLSE));

            recombinarBotoesListaEnc();
          }

}

void EstruturadeDados::on_removerInicio_clicked()
{
    if(nElementosLSE == 0)
    {
            QMessageBox::warning(this,tr("Erro!"),tr("Lista Vazia!"));
    }
    else if(nElementosLSE == 1)
    {
        QPushButton *botao = listaBotoes.first();
        listaBotoes.removeFirst();
        delete botao;

        ListaEncadeada.removeFirst();
        nElementosLSE--;
        ui->nElementos->setText(QString::number(nElementosLSE));
    }
    else
    {
        QPushButton *botao = listaBotoes.first();
        listaBotoes.removeFirst();
        delete botao;

        ListaEncadeada.removeFirst();
        nElementosLSE--;
        ui->nElementos->setText(QString::number(nElementosLSE));

        recombinarBotoesListaEnc();
     }

}

void EstruturadeDados::on_removerFim_clicked()
{
    if(ListaEncadeada.isEmpty()){
            QMessageBox::warning(this,tr("Erro!"),tr("Lista Vazia!"));
        } else{
            QPushButton *botao = listaBotoes.last();
            listaBotoes.removeLast();
            delete botao;

            ListaEncadeada.removeLast();
            nElementosLSE--;
            ui->nElementos->setText(QString::number(nElementosLSE));
          }

}

void EstruturadeDados::on_removerMeio_clicked()
{
    bool ok;
    unsigned long int pos = ui->linePosicao->text().toLong(&ok);
    if(ListaEncadeada.isEmpty()){
            QMessageBox::warning(this,tr("Erro!"),tr("Lista Vazia!"));
        }
    else if(nElementosLSE == 1){
            QPushButton *botao = listaBotoes.at(pos-1);
            listaBotoes.removeAt(pos-1);
            delete botao;

            ListaEncadeada.removeFirst();
            nElementosLSE--;
            ui->nElementos->setText(QString::number(nElementosLSE));
        }
    else if(pos > nElementosLSE || pos == 0)
    {
        QMessageBox::warning(this,tr("Erro!"),tr("Posicao Invalida!"));
    }

    else{
            QPushButton *botao = listaBotoes.at(pos-1);
            listaBotoes.removeAt(pos-1);
            delete botao;

            ListaEncadeada.removeAt(pos-1);
            nElementosLSE--;
            ui->nElementos->setText(QString::number(nElementosLSE));

            recombinarBotoesListaEnc();
          }

}

void EstruturadeDados::on_buscarPosicao_clicked()
{
    QMessageBox msg;
    bool ok;
    unsigned long int pos = ui->linePosicao->text().toLong(&ok);
    if(nElementosLSE == 0){
        QMessageBox msg;
        msg.warning(this, tr("Erro!"), tr("Lista Vazia!"));
    } else{
        msg.information(this, tr("Elemento"),QString::number(ListaEncadeada.at(pos-1)));
    }
}

void EstruturadeDados::on_buscarElemento_clicked()
{
    QMessageBox msg;
    bool ok;
    long int inteiro = ui->lineElemento->text().toLong(&ok);
    if(nElementosLSE == 0){
        QMessageBox msg;
        msg.warning(this, tr("Erro!"), tr("Lista Vazia!"));
    } else{
        msg.information(this, tr("Posição"),QString::number(ListaEncadeada.indexOf(inteiro)+1));
    }
}

//Pilha a partir daqui
void EstruturadeDados::recombinarBotoesPilha()
{
    tamanhoBotao = 25;
    escala = -25;
    eixoX = 500;
    eixoY = 150;
    int nBotoes = listaBotoes.size();
    float anguloUnidades = (45 / nBotoes);

    for(int i = 0; i < nBotoes; i++)
    {
        QPushButton *botao = listaBotoes.at(i);
        QPropertyAnimation *animation = new QPropertyAnimation(botao, "geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF((sin(anguloUnidades*i*0) * escala + eixoY),
                                      (i * escala + eixoX),
                                      tamanhoBotao,
                                      tamanhoBotao));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}


void EstruturadeDados::on_inserirPilha_clicked()
{
    bool ok;
    int numero = ui->lineInserirPilha->text().toInt(&ok);

    QPushButton *botao = new QPushButton(this);
    botao->setStyleSheet("font: 11pt ""Times New Roman"";"
                         "border-width: 1px;"
                         "border-style: solid;"
                         "border-radius: 6px;"
                         "border-color: black;"
                         "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 21, 21, 255));");
    botao->setText(QString::number(numero));
    botao->setGeometry(ui->inserirPilha->geometry());
    botao->show();
    listaBotoes.append(botao);
    Pilha.push(numero);

    nElementosPilha++;
    ui->nElemPilha->setText(QString::number(nElementosPilha));

    recombinarBotoesPilha();
}

void EstruturadeDados::on_removerPilha_clicked()
{
    if(nElementosPilha == 0){
        QMessageBox::warning(this, tr("Erro!"), tr("Lista Vazia!"));
    } else{
            QPushButton *botao = listaBotoes.last();
            listaBotoes.removeLast();
            delete botao;

            nElementosPilha--;
            Pilha.pop();
            ui->nElemPilha->setText(QString::number(nElementosPilha));
    }
}

void EstruturadeDados::on_topoPilha_clicked()
{
    QMessageBox msg;
    if(nElementosPilha == 0){
        QMessageBox msg;
        msg.warning(this, tr("Erro!"), tr("Pilha Vazia!"));
    } else{
        msg.information(this, tr("Topo"),QString::number(Pilha.top()));
    }
}
//Fila a partir daqui
void EstruturadeDados::recombinarBotoesFila()
{
    tamanhoBotao = 25;
    escala = 25;
    eixoX = 120;
    eixoY = 150;
    int nBotoes = listaBotoes.size();
    float anguloUnidades = (45 / nBotoes);

    for(int i = 0; i < nBotoes; i++)
    {
        QPushButton *botao = listaBotoes.at(i);
        QPropertyAnimation *animation = new QPropertyAnimation(botao, "geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF((i * escala + eixoX),
                                      (sin(anguloUnidades*i*0) * escala + eixoY),
                                      tamanhoBotao,
                                      tamanhoBotao));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void EstruturadeDados::on_inserirFila_clicked()
{
    bool ok;
    int numero = ui->lineInserirFila->text().toInt(&ok);

    QPushButton *botao = new QPushButton(this);
    botao->setStyleSheet("font: 11pt ""Times New Roman"";"
                         "border-width: 1px;"
                         "border-style: solid;"
                         "border-radius: 6px;"
                         "border-color: black;"
                         "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 21, 21, 255));");
    botao->setText(QString::number(numero));
    botao->setGeometry(ui->inserirFila->geometry());
    botao->show();
    listaBotoes.append(botao);

    Fila.push(numero);
    nElementosFila++;
    ui->nElemFila->setText(QString::number(nElementosFila));

    recombinarBotoesFila();
}

void EstruturadeDados::on_removerFila_clicked()
{
    if(nElementosFila == 0){
        QMessageBox msg;
        msg.warning(this, tr("Erro!"), tr("Lista Vazia!"));

    }
    else if(nElementosFila == 1)
    {
        QPushButton *botao = listaBotoes.first();
        listaBotoes.removeFirst();
        delete botao;
        Fila.pop_front();
        nElementosFila--;
        ui->nElemFila->setText(QString::number(nElementosFila));
    }
    else
    {
        QPushButton *botao = listaBotoes.first();
        listaBotoes.removeFirst();
        delete botao;
        recombinarBotoesFila();
        Fila.pop_front();
        nElementosFila--;
        ui->nElemFila->setText(QString::number(nElementosFila));
    }
}

void EstruturadeDados::on_primeiroFila_clicked()
{
    QMessageBox msg;
    if(nElementosFila == 0){
        QMessageBox msg;
        msg.warning(this, tr("Erro!"), tr("Lista Vazia!"));
    } else{
        msg.information(this, tr("Primeiro"),QString::number(Fila.first()));
    }
}

//Arv Binaria a partir daqui
void EstruturadeDados::on_arvBin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void EstruturadeDados::on_voltar_1_clicked()
{
    for(int i = nElementosArv; i > 0; i--){
    QPushButton *botao = listaBotoes.last();
    listaBotoes.removeLast();
    delete botao;
    nElementosArv--;
    ui->nNos->setText(QString::number(nElementosArv));
    }

    ui->stackedWidget->setCurrentIndex(0);
}

void EstruturadeDados::recombinarBotoesBSTDir()
{
    tamanhoBotao = 25;
    escala = 30;
    eixoX = 430;
    eixoY = 60;
    int nBotoes = listaBotoes.size();
    //float anguloUnidades = (45 / nBotoes);
    for(int i = 0; i < nBotoes; i++)
    {
        QPushButton *botao = listaBotoes.at(i);
        QPropertyAnimation *animation = new QPropertyAnimation(botao, "geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF((1.25*i * escala + eixoX),
                                      (i * escala + eixoY),
                                      tamanhoBotao,
                                      tamanhoBotao));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void EstruturadeDados::recombinarBotoesBSTEsq()
{
    tamanhoBotao = 25;
    escala = 30;
    eixoX = 430;
    eixoY = 60;
    int nBotoes = listaBotoes.size();
    //float anguloUnidades = (45 / nBotoes);

    for(int i = 0; i < nBotoes; i++)
    {
        QPushButton *botao = listaBotoes.at(i);
        QPropertyAnimation *animation = new QPropertyAnimation(botao, "geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF((-1.25*i * escala + eixoX),
                                      (i * escala + eixoY),
                                      tamanhoBotao,
                                      tamanhoBotao));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void EstruturadeDados::on_inserirArvore_clicked()
{
    bool ok;
    int inteiro = ui->lineArvore->text().toLong(&ok);

        QPushButton *botao = new QPushButton(this);
        botao->setStyleSheet("font: 11pt ""Times New Roman"";"
                             "border-width: 1px;"
                             "border-style: solid;"
                             "border-radius: 11px;"
                             "border-color: black;"
                             "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(234, 234, 234, 255), stop:1 rgba(255, 21, 21, 255));");
        botao->setText(QString::number(inteiro));
        botao->setGeometry(ui->inserirPilha->geometry());
        botao->show();
        listaBotoes.append(botao);

        BST.inserir(inteiro);
        nElementosArv++;
        ui->nNos->setText(QString::number(nElementosArv));
        recombinarBotoesBSTEsq();
}


void EstruturadeDados::on_buscaArvore_clicked()
{
    QMessageBox msg;
    bool ok;
    if(BST.buscar(ui->lineArvore->text().toLong(&ok))){
        msg.information(this, tr("Buscar"), tr("Encontrado!"));
    } else{
        QMessageBox msg;
        msg.warning(this, tr("Erro!"), tr("Não encontrado!"));
    }
}
