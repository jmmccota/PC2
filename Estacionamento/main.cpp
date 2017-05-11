#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <istream>
#include <cstdlib>

#include "Estacionamento.h"
#include "Vaga.h"
#include "Veiculo.h"
#include "Calendar.h"

using namespace std;

int vagaLivre(Estacionamento *e);

string StringToUpper(string strToConvert)
{
    for(unsigned int i=0; i<strToConvert.length(); i++)
    {
        strToConvert[i] = toupper(strToConvert[i]);
    }
    return strToConvert;//return the converted string
}


int main(int argc, char** argv)
{

    cout<<fixed<<setprecision(2); //deixar valores arredondados com 2 casas decimais e.g. 234,55

    //eliminar comentarios!
    int tam;
    cout<<"\nEntre com o tamanho do estacionamento: ";
    cin>>tam;
    Estacionamento e(tam);
    int ctrl,ctrl2;
    do
    {
        cout<<"\n-----Parking Lot---------\n| 1 - Administrador     |\n| 2 - Atendente         |\n| 0 - Sair              |\n-------------------------\n";
        cin>>ctrl;
        if(ctrl == 1)
        {
//-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//
            do
            {
                cout<<"\n-----Administrativo-------\n| 1 - Alterar tamanho   |\n| 2 - Alterar tarifas   |\n| 3 - Ver Relatorios    |\n| 4 - Info. de Tarifas  |\n| 0 - Sair              |\n-------------------------\n";
                cin>>ctrl2;
                if(ctrl2 == 1)
                {
                    Vaga **vvet = e.getVagas();

                    int qtde;

                    cout<<"\nEntre com a nova quantidade de vagas do estacionamento, deve ser maior ou igual a "<<e.getQVagas()<<" \n";
                    cin>>qtde;

                    if(qtde > e.getQVagas())
                    {
                        Vaga **aux = new Vaga*[qtde];
                        for(int i = 0; i < qtde; i++)
                        {
                            aux[i] = vvet[i];
                        }
                        e.setVagas(aux, qtde);
                    }
                    else
                    {
                        cout<<"\nTamanho errado, tente novamente\n";
                    }
                }
                else if(ctrl2 == 2)
                {
                    cout<<"\nEntre com a quantidade de tarifas (0 - Sair) \n";
                    int qtde;
                    cin>>qtde;
                    if(qtde > 0)
                    {
                        cout<<"\nEntre com a descrição e valor pras "<<qtde<<" tarifas\n";
                        float *val = new float[qtde];
                        string *tipos = new string[qtde];

                        for(int i = 0; i<qtde; i++)
                        {
                            cout<<"\n Descricao:";
                            cin>>tipos[i];
                            cout<<"\n Valor:";
                            cin>>val[i];
                        }
                        e.setTarifas(val,tipos,qtde);
                    }
                }
                else if(ctrl2 == 3)
                {
                    int ctrl3;
                    do
                    {
                        cout<<"\n-----Relatorios----------\n| 1 - Qtde. Veiculos    |\n| 2 - Lista de Todos os Veiculos |\n| 3 - Dados de um Veic.  |\n| 4 - Lista Veiculo Dia.|\n| 5 - Listagem por Piso |\n| 0 - Sair              |\n-------------------------\n";
                        cin>>ctrl3;
                        if(ctrl3 == 1)
                        {
                            cout<<"\nExiste(m) "<<e.getQVeiculosEstacionados()<<" Veiculo(s) registrado(s)\n";
                        }
                        else if(ctrl3 == 2)
                        {
                            Veiculo **vvet = e.getVeiculos();
                            cout<<"\n Vetor:"<< *(e.getVeiculos());

                            cout<<"\n Veiculo"<<vvet[0]->getPlaca();
                            cout<<"\n Veiculo"<<vvet[0]->getCor();
                            cout<<"\n Vei:"<<vvet[0]->getMarca();

                            if(e.getQVeiculos()>0)
                            {
                                cout<<"\n|-Placa\tMarca\tModelo--|\n";

                                for(int i = 0; i < e.getQVeiculosEstacionados(); i++)
                                {

                                    cout<<"\n| "<<vvet[i]->getPlaca()<<" \t "<<vvet[i]->getMarca()<<" \t "<<vvet[i]->getModelo()<<" |\n";
                                }
                            }
                            else cout<<"\n Não existem veiculos estacionados";

                        }
                        else if(ctrl3 == 3)
                        {
                            Veiculo **vvet = e.getVeiculos();

                            if(e.getQVeiculos()>=0)
                            {

                                string placa;
                                cout<<"\nEntre com a placa do veiculo a ser pesquisado\n";
                                cin>>placa;
                                placa = StringToUpper(placa);
                                for(int i = 0; i < e.getQVeiculos()-1; i++)
                                {
                                    if(placa == vvet[i]->getPlaca())
                                    {
                                        cout<<"\nPlaca: "<<vvet[i]->getPlaca();
                                        cout<<"\nMarca: "<<vvet[i]->getMarca();
                                        cout<<"\nModelo: "<<vvet[i]->getModelo();
                                        cout<<"\nCor: "<<vvet[i]->getCor();
                                        cout<<"\nQuantidade de estacionamentos: "<<vvet[i]->getQEstacionado();
                                    }
                                }
                            }
                            else cout<<"\n Não existem veiculos estacionados";

                        }/**else if(ctrl3 == 4){
							cout<<"\nInformações Sobre Tarifas\n";
							cout<<"\n|-Descrição------------Valor----|\n";
							float *valores = e.getValores();
							string *tvalores = e.getTValores();
							for(int i = 0; i<(sizeof(valores)/sizeof(int)); i++){
								cout<<"\n-"<<tvalores[i]<<"-----"<<valores<<"-\n";
							}
						}**/else if(ctrl3 == 4)
                        {
                            Calendar c;
                            int diahoje;
                            //time_t data;
                            int diaEstaciona;
                            int qtdDia;

                            Veiculo **vvet = e.getVeiculos();

                            if(e.getQVeiculos()>0)
                            {
                                time_t currentTime;
                                time(&currentTime);

                                struct tm * ptm = localtime(&currentTime);
                                diahoje= c.pegaDia(currentTime);
                                cout<<"\n Listagem Dia:";

                                //cout<<"\n List:"<<e.getQVeiculos();

                                for(int i = 0; i < e.getQVeiculos()-1; i++)
                                {
                                    if(vvet[i]->isEstacionado()){
                                    diaEstaciona=vvet[i]->getDiaEntrada();

                                    if(diahoje==diaEstaciona)
                                    {
                                        cout<<"\nPlaca: "<<vvet[i]->getPlaca();
                                        cout<<"\nMarca: "<<vvet[i]->getMarca();
                                        cout<<"\nModelo: "<<vvet[i]->getModelo();
                                        cout<<"\nCor: "<<vvet[i]->getCor();
                                    }
                                    }
                                    cout<<"\n";
                                }

                            }
                            else
                            {
                                cout<<"\n Não existem veiculos estacionados";
                            }
                            //time_t hora = currentTime - <vaga>.getHorarioInicio();
                            //struct tm2 * ptm2 = localtime(&hora) // provavelmente deve retornar o tempo que o carro ficou estacionado
                            //int dia = ptm->tm_mday; //para pegar o dia
                            //int hora = ptm->tm_hour //para pegar hora no formato 0-23
                        }
                        else if(ctrl3 == 5)
                        {
                            Vaga **vet = e.getVagas();
                            //Veiculo **vet=e.getVeiculos();

                            if(e.getQVagas()>0)
                            {
                                int piso;
                                cout<<"\nEntre com o piso: ";
                                cin>>piso;
                                for(int i = 0; i<e.getQVeiculos(); i++)
                                {
                                    if(vet[i]->getPiso() == piso)
                                    {
                                        if(vet[i]->getVeiculo()->isEstacionado())
                                        {
                                            cout<<"\nA vaga esta ocupada por: ";
                                            cout<<" Placa: "<<vet[i]->getVeiculo()->getPlaca();
                                            cout<<" Marca: "<<vet[i]->getVeiculo()->getMarca();
                                            cout<<" Modelo: "<<vet[i]->getVeiculo()->getModelo();
                                            cout<<endl;
                                        }
                                    }
                                }
                            }
                            else cout<<"\n Não existem veiculos estacionados";

                        }
                        else if(ctrl3 != 0)
                        {
                            cout<<"\nEscolha uma opção valida!!\n";
                        }
                        else
                        {
                            cout<<"\nVoce saiu!!!\n";
                        }
                    }
                    while(ctrl3 != 0);
                }
                else if(ctrl2 == 4)
                {
                    //float *valores = e.getValores();
                    //cout<<"\n valores:"<<*(e.getValores());
                    if(*(e.getValores()) > -0)
                    {
                        cout<<"\nInformações Sobre Tarifas\n";
                        cout<<"\n|-Descrição\tValor----|\n";
                        float *valores = e.getValores();
                        string *tvalores = e.getTValores();
                        for(int i = 0; i<e.getQTipos(); i++)
                        {
                            cout<<"\n-"<<tvalores[i]<<"\t\t R$"<<valores[i]<<"-\n";
                        }
                    }
                    else
                    {
                        cout<<"\n Não existem Tarifas Cadastradas!\n";
                    }
                }
                else if(ctrl2 != 0)
                {
                    cout<<"\nEscolha uma opção valida!!\n";
                }
                else
                {
                    cout<<"\nVoce saiu!!!\n";
                }
            }
            while(ctrl2 != 0);
//-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//
        }
        else if(ctrl == 2)
        {
//-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//
            cout<<"\n-------Atendente---------\n| 1 - Estacionar Veiculo |\n| 2 - Consultar Veiculo |\n| 0 - Sair              |\n-------------------------\n";
            cin>>ctrl2;
            if(ctrl2 == 1)
            {
                string placa;
                cout<<"\nEntre com a placa do veiculo que deseja ser estacionado (Formato: ABC-1234):\n";
                cin>>placa;
                placa = StringToUpper(placa);
                //cout<<"ValorQ:"<<e.getQVeiculos();

                if(e.getQVeiculosEstacionados() > 0)
                {
                    //Veiculo **vvet = e.getVeiculos();
                    if((e.getVeiculo(placa) == NULL))
                    {

                        if(vagaLivre(&e) != -1)
                        {
                            string marca, modelo, cor;
                            int selecao, piso, numero;

                            cout<<"\nMarca:";
                            cin>>marca;
                            cout<<"\nModelo:";
                            cin>>modelo;
                            cout<<"\nCor:";
                            cin>>cor;
                            cout<<"\nTipo:"<<endl;
                            for(int k = 0; k<e.getQTipos(); k++)
                            {
                                cout<<k<<" - ";
                                cout<<e.getValores()[k]<<"\t";
                                cout<<e.getTValores()[k]<<endl;
                            }
                            cout<<endl;
                            cin>>selecao;
                            Veiculo *v = new Veiculo(marca, modelo, cor, placa,selecao);

                            time_t hourEntrada;
                            time(&hourEntrada);
                            struct tm * ptm = localtime(&hourEntrada);
                            v->setEntrada(hourEntrada);
                            v->estaciona();

                            Vaga *pos = e.getVaga(vagaLivre(&e));
                            cout<<"\nEntre com dados da Vaga:\n";
                            cout<<"\nPiso: ";
                            cin>>piso;
                            cout<<"\nNumero: ";
                            cin>>numero;

                            pos->setEstado(true); //ocupada

                            pos->setNumero(numero);
                            pos->setPiso(piso);
                            /**(*pos).setPiso(piso); //mesmo que ->**/
                            pos->setVeiculo(v);
                            e.addVaga(pos); //talvez não necessario pelo uso de ponteiros
                            e.estaciona(v);
                            cout<<"\nEstacionado com exito!\n";
                      }
                        else
                        {
                            cout<<"\nEstacionamento Lotado!\n";
                        }
                    }
                    else
                    {

                        cout<<"\n!!Veiculo já cadastrado!!\n";
                        cout<<"\nMarca "<<e.getVeiculo(placa)->getMarca()<<" Modelo: "<<e.getVeiculo(placa)->getModelo()<<endl;
                        if(vagaLivre(&e) != -1)
                        {
                            cout<<"\n VEstacionado:"<<e.getVeiculo(placa)->isEstacionado();

                            if(!e.getVeiculo(placa)->isEstacionado())
                            {
                                char opc;
                                cout<<"\nDeseja estacionar? (S - sim | N- não) ";
                                cin>>opc;
                                if(opc == 's' || opc == 'S')
                                {
                                    Vaga *pos = e.getVaga(vagaLivre(&e));
                                    pos->setVeiculo(e.getVeiculo(placa));

                                    time_t hourEntrada;
                                    time(&hourEntrada);
                                    struct tm * ptm = localtime(&hourEntrada);
                                    Veiculo *vEstacionado= e.getVeiculo(placa);
                                    vEstacionado->setEntrada(hourEntrada);
                                    vEstacionado->estaciona();

                                    e.addVaga(pos); //talvez não necessario pelo uso de ponteiros
                                    cout<<"\nEstacionado com exito!\n";
                                }
                                else
                                {
                                    cout<<"\nVc saiu!\n";
                                }
                            }
                        }
                    }
                }
                else if (e.getQVeiculosEstacionados() == 0)
                {
                    if((vagaLivre(&e) != -1))
                    {
                        string marca, modelo, cor;
                        int selecao, piso, numero;
                        cout<<"\nMarca:";
                        cin>>marca;
                        cout<<"\nModelo:";
                        cin>>modelo;
                        cout<<"\nCor:";
                        cin>>cor;
                        cout<<"\nTipo:\n ";
                        for(int k = 0; k<e.getQTipos(); k++)
                        {
                            cout<<k<<" - ";
                            cout<<e.getValores()[k]<<"\t";
                            cout<<e.getTValores()[k]<<endl;
                        }
                        cout<<endl;
                        cin>>selecao;
                        Veiculo *v = new Veiculo(marca, modelo, cor, placa,selecao);

                        time_t hourEntrada;
                        time(&hourEntrada);
                        struct tm * ptm = localtime(&hourEntrada);
                        v->setEntrada(hourEntrada);
                        v->estaciona();

                        Vaga *pos = e.getVaga(vagaLivre(&e));
                        cout<<"\nEntre com dados da Vaga:\n";
                        cout<<"\nPiso: ";
                        cin>>piso;
                        cout<<"\nNumero: ";
                        cin>>numero;

                        pos->setEstado(true); //ocupada

                        pos->setNumero(numero);
                        pos->setPiso(piso);
                        //	(*pos).setPiso(piso); //mesmo que ->

                        pos->setVeiculo(v);
                        //cout<<"\n End. vaga:"<<pos;
                        //cout<<"\n End veic:"<<v;

                        e.addVaga(pos); //talvez não necessario pelo uso de ponteiros
                        e.estaciona(v);
                        cout<<"\nEstacionado com exito!\n";
                        //cout<<"\n Veiculo:"<<v->isEstacionado();
                    }
                    else
                    {
                        cout<<"\nEstacionamento Lotado!\n";
                    }
                }
            }
            else if(ctrl2 == 2)
            {
                cout<<"\nInsira a Placa para ser consultada\n";
                string placa;
                cin>>placa;
                placa = StringToUpper(placa);
                Veiculo *v = e.getVeiculo(placa);
                Calendar c;

                if(v != NULL)
                {
                    cout<<"\nPlaca: "<<v->getPlaca();
                    cout<<"\nMarca: "<<v->getMarca();
                    cout<<"\nModelo: "<<v->getModelo();
                    cout<<"\nCor: "<<v->getCor();
                    cout<<"\nEstacionado: ";
                    if(v->isEstacionado())
                    {
                        cout<<"\nVeiculo estacionado\n Deseja retira-lo? (S - Sim | Não)\n";
                        char opc;
                        cin>>opc;
                        if(opc == 's' || opc == 'S')
                        {
                            for(int i = 0; i<e.getQVagas(); i++)
                            {
                                if((e.getVagas()[i]->getVeiculo()->getPlaca() == placa) && (e.getVagas()[i]->isOcupado()))
                                {
                                    double seconds;
                                    double convertHour;
                                    double taxaTarifa=0;

                                    time_t hourSaida;
                                    time(&hourSaida);
                                    struct tm * ptm = localtime(&hourSaida);
                                    v->setSaida(hourSaida);

                                    seconds = difftime(v->getSaida(),v->getEntrada());
                                    convertHour=seconds/3600;

                                    for(int k = 0; k<e.getQTipos(); k++)
                                    {

                                        if(v->getTipo()==k)
                                        {

                                            taxaTarifa= e.getValores()[k]*convertHour;
                                            cout<<" O valor da tarifa a ser paga é de: R$"<<taxaTarifa;
                                        }

                                    }
                                    v->setEstaciona(false);
                                }
                                break;
                            }
                        }
                    }
                }
                else
                {
                    cout<<"\nVeiculo não esta estacionado\n";
                }
            }
            /**else {
            		cout<<"\nVeiculo não cadastrado\n";
            	}

            	} else if(ctrl2 == 3) {

            	if(ctrl == 1) {

            	} else if(ctrl != 0) {
            		cout<<"\nEscolha uma opção valida!!\n";
            	} else {
            		cout<<"\nVoce saiu!!!\n";
            	}
            */
            else if(ctrl2 != 0)
            {
                cout<<"\nEscolha uma opção valida!!\n";
            }
            else
            {
                cout<<"\nVoce saiu!!!\n";
            }
//-----------------------------------------------------------------------//
//-----------------------------------------------------------------------//
        }
        else if(ctrl != 0)
        {
            cout<<"\nEscolha uma opção valida!!\n";
        }
        else
        {
            cout<<"\nVoce saiu!!!\n";
        }

    }
    while(ctrl != 0);

    system("pause");
    return 0;
}

int vagaLivre(Estacionamento *e)  //Facilitar, foi usada varias vezes
{
    //cout<<"\n Vagas em vagaLivre:"<<e->getQVeiculos();
    Vaga **v = e->getVagas();

    for(int i = 0; i<e->getQVagas(); i++)
    {
        if(!v[i]->isOcupado())
        {
            return i;
        }
    }
    return -1;
}
