#ifndef ESTRUTURADEDADOS_H
#define ESTRUTURADEDADOS_H
#include <QList>
#include <QMainWindow>
#include <QMessageBox>
#include <QStack>
#include <QDebug>
#include "math.h"
#include <QPropertyAnimation>
#include <QPushButton>
#include "BinarySearchTree.h"

namespace Ui {
class EstruturadeDados;
}

class EstruturadeDados : public QMainWindow
{
    Q_OBJECT

public:
    explicit EstruturadeDados(QWidget *parent = 0);

    ~EstruturadeDados();

private slots:
    void on_listaEnc_clicked();

    void on_pilha_clicked();

    void on_fila_clicked();

    void on_voltar1_clicked();

    void on_voltar2_clicked();

    void on_voltar3_clicked();

    void on_voltar4_clicked();

    void on_inserirInicio_clicked();

    void on_inserirFim_clicked();

    void on_inserirMeio_clicked();

    void on_removerInicio_clicked();

    void on_removerFim_clicked();

    void on_removerMeio_clicked();

    void on_inserirPilha_clicked();

    void on_removerPilha_clicked();

    void on_inserirFila_clicked();

    void on_removerFila_clicked();

    void on_primeiroFila_clicked();

    void on_topoPilha_clicked();

    void on_arvBin_clicked();

    void on_voltar_1_clicked();

    void on_buscarPosicao_clicked();

    void on_buscarElemento_clicked();

    void on_inserirArvore_clicked();

    void on_buscaArvore_clicked();



private:
    Ui::EstruturadeDados *ui;
    int eixoX, eixoY, escala, tamanhoBotao;
    QList <QPushButton*> listaBotoes;

    void recombinarBotoesPilha();
    void recombinarBotoesFila();
    void recombinarBotoesListaEnc();

    void recombinarBotoesBSTEsq();

    void recombinarBotoesBSTDir();

};

#endif // ESTRUTURADEDADOS_H
