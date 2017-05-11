#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include "SplitString.h"

#include "Sistema.h"
#include "DVD_Software.h"
#include "DVD_Filme.h"
#include "DVD_Show.h"
#include "Livro.h"
#include "Perfume.h"
#include "Relogio.h"

using namespace std;

string pegaData(time_t data) {
    int dia, mes, ano;
    time(&data);
    struct tm * ptm = localtime(&data);
    dia = ptm->tm_mday;
    mes = ptm->tm_mon + 1;
    ano = ptm->tm_year + 1900;
    stringstream ss;
    ss << dia << "/" << mes << "/" << ano;
    string s = ss.str();
    return s;
}

void salva(Sistema *s) {
    vector<Produto*>::iterator p;
    ostringstream os;
    os << "Produtos.dat";
    ofstream fProd(os.str().c_str());
    for (p = s->getProdutos()->begin(); p < s->getProdutos()->end(); p++) {
        if ((*p)->GetTipo() == "Livro") {
            Livro *tmp = static_cast<Livro*> ((*p));
            fProd << tmp->GetTipo() << "|" << tmp->GetCodigo() << "|" << tmp->GetNome() << "|" << tmp->GetPreco() << "|" << tmp->GetQuantNoEstoque() <<
                    "|" << tmp->getAutor() << "|" << tmp->getGenero() << endl;
        } else if ((*p)->GetTipo() == "Show") {
            DVD_Show *tmp = static_cast<DVD_Show*> ((*p));
            fProd << tmp->GetTipo() << "|" << tmp->GetCodigo() << "|" << tmp->GetNome() << "|" << tmp->GetPreco() << "|" << tmp->GetQuantNoEstoque() <<
                    "|" << tmp->GetArtista() << "|" << tmp->GetNumMusicas() << "|" << tmp->GetAno() << endl;
        } else if ((*p)->GetTipo() == "Software") {
            DVD_Software *tmp = static_cast<DVD_Software*> ((*p));
            fProd << tmp->GetTipo() << "|" << tmp->GetCodigo() << "|" << tmp->GetNome() << "|" << tmp->GetPreco() << "|" << tmp->GetQuantNoEstoque() <<
                    "|" << tmp->GetVersao() << "|" << tmp->GetRequisitos() << "|" << tmp->GetAno() << endl;
        } else if ((*p)->GetTipo() == "Filme") {
            DVD_Filme *tmp = static_cast<DVD_Filme*> ((*p));
            fProd << tmp->GetTipo() << "|" << tmp->GetCodigo() << "|" << tmp->GetNome() << "|" << tmp->GetPreco() << "|" << tmp->GetQuantNoEstoque() <<
                    "|" << tmp->GetDiretor() << "|" << tmp->GetAno() << endl;
        } else if ((*p)->GetTipo() == "Perfume") {
            Perfume *tmp = static_cast<Perfume*> ((*p));
            fProd << tmp->GetTipo() << "|" << tmp->GetCodigo() << "|" << tmp->GetNome() << "|" << tmp->GetPreco() << "|" << tmp->GetQuantNoEstoque() <<
                    "|" << tmp->getMarca() << "|" << tmp->getMl() << endl;
        } else if ((*p)->GetTipo() == "Relogio") {
            Relogio *tmp = static_cast<Relogio*> ((*p));
            fProd << tmp->GetTipo() << "|" << tmp->GetCodigo() << "|" << tmp->GetNome() << "|" << tmp->GetPreco() << "|" << tmp->GetQuantNoEstoque() <<
                    "|" << tmp->getMarca() << "|" << tmp->getTipo() << endl;
        }
    }
    fProd.close();
	
    vector<Usuario*>::iterator u;
    ostringstream os2;

    os2 << "Usuarios.dat";
    ofstream fUsu(os2.str().c_str());
    for (u = s->getUsuarios()->begin(); u < s->getUsuarios()->end(); u++) {
        fUsu << (*u)->GetCpf() << "|" << (*u)->GetEndereco() << "|" << (*u)->GetNasc() << "|" << (*u)->GetNome() << "|" << (*u)->GetTelefone() << endl;
    }
    fUsu.close();

    vector<Venda*>::iterator v;
    ostringstream os3;

    os3 << "Vendas.dat";
    ofstream fVendas(os3.str().c_str());
    for (v = s->getVendas()->begin(); v < s->getVendas()->end(); v++) {
        fVendas << (*v)->GetCodigo() << "|" << (*v)->GetData() << "|" << (*v)->GetValorFrete() << "|" << (*v)->GetValorTotalCompra() << "|" << (*v)->GetUsuario()->GetCpf() << "|";
        vector<Item*>::iterator p;
        for (p = (*v)->GetCarrinho()->getItem()->begin(); p < (*v)->GetCarrinho()->getItem()->end(); p++) {
            fVendas << (*p)->GetProduto()->GetCodigo() << "|" << (*p)->GetPreco() << "|" << (*p)->GetQuantidade() << endl;
        }
    }
    fVendas.close();
	
}

void carrega(Sistema *s) {
    string line;
    string saida;
    ifstream prod("Produtos.dat");
    if (prod.is_open()) {
        while (prod.good()) {
            getline(prod, line);
            SplitString ss(line);
            vector<string> flds = ss.split('|');
            if (flds.size() > 0) {
                if (flds[0] == "Livro") {
                    Livro *tmp = new Livro();
                    tmp->SetCodigo(atoi(flds[1].c_str()));
                    tmp->SetNome(flds[2]);
                    tmp->SetPreco(atof(flds[3].c_str()));
                    tmp->SetQuantNoEstoque(atof(flds[4].c_str()));

                    tmp->setAutor(flds[5]);
                    tmp->setAutor(flds[6]);
                    s->cadastrar(tmp);
                } else if (flds[0] == "Show") {
                    DVD_Show *tmp = new DVD_Show();
                    tmp->SetCodigo(atoi(flds[1].c_str()));
                    tmp->SetNome(flds[2]);
                    tmp->SetPreco(atof(flds[3].c_str()));
                    tmp->SetQuantNoEstoque(atof(flds[4].c_str()));

                    tmp->SetArtista(flds[5]);
                    tmp->SetNumMusicas(atoi(flds[6].c_str()));
                    tmp->SetAno(atoi(flds[7].c_str()));
                    s->cadastrar(tmp);

                } else if (flds[0] == "Software") {
                    DVD_Software *tmp = new DVD_Software();
                    tmp->SetCodigo(atoi(flds[1].c_str()));
                    tmp->SetNome(flds[2]);
                    tmp->SetPreco(atof(flds[3].c_str()));
                    tmp->SetQuantNoEstoque(atof(flds[4].c_str()));

                    tmp->SetVersao(flds[5]);
                    tmp->SetRequisitos(flds[6]);
                    tmp->SetAno(atoi(flds[7].c_str()));
                    s->cadastrar(tmp);
                } else if (flds[0] == "Filme") {
                    DVD_Filme *tmp = new DVD_Filme();
                    tmp->SetCodigo(atoi(flds[1].c_str()));
                    tmp->SetNome(flds[2]);
                    tmp->SetPreco(atof(flds[3].c_str()));
                    tmp->SetQuantNoEstoque(atof(flds[4].c_str()));

                    tmp->SetDiretor(flds[5]);
                    tmp->SetAno(atoi(flds[6].c_str()));
                    s->cadastrar(tmp);
                } else if (flds[0] == "Perfume") {
                    Perfume *tmp = new Perfume();
                    tmp->SetCodigo(atoi(flds[1].c_str()));
                    tmp->SetNome(flds[2]);
                    tmp->SetPreco(atof(flds[3].c_str()));
                    tmp->SetQuantNoEstoque(atof(flds[4].c_str()));

                    tmp->setMarca(flds[5]);
                    tmp->setMl(atof(flds[6].c_str()));
                    s->cadastrar(tmp);
                } else if (flds[0] == "Relogio") {
                    Relogio *tmp = new Relogio();
                    tmp->SetCodigo(atoi(flds[1].c_str()));
                    tmp->SetNome(flds[2]);
                    tmp->SetPreco(atof(flds[3].c_str()));
                    tmp->SetQuantNoEstoque(atof(flds[4].c_str()));

                    tmp->setMarca(flds[5]);
                    tmp->setTipo(atoi(flds[6].c_str()));
                    s->cadastrar(tmp);
                }
            }
        }
    }
    prod.close();
	
    ifstream usu("Usuarios.dat");
    if (usu.is_open()) {
        while (usu.good()) {
            getline(usu, line);
            SplitString ss(line);
            vector<string> flds = ss.split('|');
            if (flds.size() > 0) {
                Usuario *u = new Usuario();
                u->SetCpf(flds[0]);
                u->SetEndereco(flds[1]);
                u->SetNasc(flds[2]);
                u->SetNome(flds[3]);
                u->SetTelefone(flds[4]);
                s->addUsuario(u);
            }
        }
    }
    usu.close();
	
    ifstream vend("Vendas.dat");
    if (vend.is_open()) {
        while (vend.good()) {
            getline(vend, line);
            SplitString ss(line);
            vector<string> flds = ss.split('|');
            if (flds.size() > 0) {
                Venda *v = new Venda();
                v->setCodigo(atoi(flds[0].c_str()));
                //v->SetData(flds[1]);
                v->setValorFrete(atof(flds[2].c_str()));
                v->setValorTotalCompra(atof(flds[3].c_str()));
                vector<Usuario*>::iterator p;
                for (p = s->getUsuarios()->begin(); p < s->getUsuarios()->end(); p++) {
                    if ((*p)->GetCpf() == flds[4]) {
                        v->SetUsuario((*p));
                        break;
                    }
                }
                Carrinho *cc = new Carrinho();
                unsigned int j = 5;
                while (j < flds.size()) {
                    Item *i = new Item();
                    vector<Produto*>::iterator p;
                    for (p = s->getProdutos()->begin(); p < s->getProdutos()->end(); p++) {
                        if ((*p)->GetCodigo() == atoi(flds[j].c_str())) {
                            i->SetProduto((*p));
                            break;
                        }
                    }
                    i->SetPreco(atof(flds[j + 1].c_str()));
                    i->SetQuantidade(atof(flds[j + 2].c_str()));
                    cc->addItem(i);
                    j += 2;
                }
                s->addVenda(v);
            }
        }
    }
}

int main(int argc, char** argv) {
    cout << fixed << setprecision(2);
    Sistema s;
    carrega(&s);
    int op, op2;
    do {
        cout << "\t##  Menu  ##\n";
        cout << "1 - Administrador\n";
        cout << "2 - Venda\n";
        cout << "0 - Sair\n\n";
        cin >> op;

        if (op == 1) {
            do {
                cout << "\t##  Administrador  ##\n";
                cout << "1 - Cadastro de Produtos\n";
                cout << "2 - Exclusao de Produtos\n";
                cout << "3 - Altera Produtos\n";
                cout << "4 - Relatorios\n";
                cout << "0 - Sair\n";
                cin >> op2;
                if (op2 == 1) {
                    int prod;
                    Produto *p;
                    float preco, qtde;
                    string descricao;
                    cout << "\nEscolha o tipo do Produto:\n";
                    cout << "1 - Dvd de Software\n";
                    cout << "2 - Dvd de Show\n";
                    cout << "3 - Dvd de Filme\n";
                    cout << "4 - Livro\n";
                    cout << "5 - Relogio\n";
                    cout << "6 - Perfume\n";
                    cin >> prod;
                    if (prod == 1) {
                        int ano;
                        string versao, requisitos;
                        cout << "Entre com\nDescricao: ";
                        fflush(stdin);
                        getline(cin, descricao);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade em estoque: ";
                        cin >> qtde;
                        cout << "\nVersao: ";
                        fflush(stdin);
                        getline(cin, versao);
                        cout << "\nRequisitos: ";
                        fflush(stdin);
                        getline(cin, requisitos);
                        cout << "\nAno: ";
                        cin >> ano;
                        p = new DVD_Software(descricao, preco, qtde, versao, ano, requisitos);
                        if (s.cadastrar(p)) {
                            cout << "\nProduto cadastrado com sucesso!\n";
                        } else {
                            cout << "\nFalha ao cadastrar o produto!\n";
                        }
                    } else if (prod == 2) {
                        int ano, qtdeM;
                        string artista;
                        cout << "Entre com\nDescricao: ";
                        fflush(stdin);
                        getline(cin, descricao);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade em estoque: ";
                        cin >> qtde;
                        cout << "\nQuantidade de musicas: ";
                        cin >> qtdeM;
                        cout << "\nArtista: ";
                        fflush(stdin);
                        getline(cin, artista);
                        cout << "\nAno: ";
                        cin >> ano;
                        p = new DVD_Show(descricao, preco, qtde, artista, qtdeM, ano);
                        if (s.cadastrar(p)) {
                            cout << "\nProduto cadastrado com sucesso!\n";
                        } else {
                            cout << "\nFalha ao cadastrar o produto!\n";
                        }
                    } else if (prod == 3) {
                        string diretor;
                        int ano;
                        cout << "Entre com \nDescricao: ";
                        fflush(stdin);
                        getline(cin, descricao);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade em estoque: ";
                        cin >> qtde;
                        cout << "\nDiretor: ";
                        fflush(stdin);
                        getline(cin, diretor);
                        cout << "\nAno: ";
                        cin >> ano;
                        p = new DVD_Filme(descricao, preco, qtde, diretor, ano);
                        if (s.cadastrar(p)) {
                            cout << "\nProduto cadastrado com sucesso!\n";
                        } else {
                            cout << "\nFalha ao cadastrar o produto!\n";
                        }
                    } else if (prod == 4) {
                        string genero, autor;
                        cout << "Entre com\nDescricao: ";
                        fflush(stdin);
                        getline(cin, descricao);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade em estoque: ";
                        cin >> qtde;
                        cout << "\nAutor: ";
                        fflush(stdin);
                        getline(cin, autor);
                        cout << "\nGenero: ";
                        fflush(stdin);
                        getline(cin, genero);
                        p = new Livro(preco, qtde, descricao, autor, genero);
                        if (s.cadastrar(p)) {
                            cout << "\nProduto cadastrado com sucesso!\n";
                        } else {
                            cout << "\nFalha ao cadastrar o produto!\n";
                        }
                    } else if (prod == 5) {
                        string marca;
                        int y;
                        cout << "Entre com \nNome: ";
                        fflush(stdin);
                        getline(cin, descricao);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade em estoque: ";
                        cin >> qtde;
                        cout << "\nMarca: ";
                        fflush(stdin);
                        getline(cin, marca);
                        do {
                            cout << "\nTipo: ";
                            cout << "\n0 - Analogico ";
                            cout << "\n1 - Digital ";
                            cin >> y;
                        } while (!((y != 0) || (y != 1)));
                        if (y == 0) //ana = False
                        {
                            p = new Relogio(preco, qtde, descricao, marca, true);
                        } else {
                            p = new Relogio(preco, qtde, descricao, marca, false);
                        }
                        if (s.cadastrar(p)) {
                            cout << "\nProduto cadastrado com sucesso!\n";
                        } else {
                            cout << "\nFalha ao cadastrar o produto!\n";
                        }
                    } else if (prod == 6) {
                        float ml;
                        string marca;
                        cout << "Entre com\nDescricao: ";
                        fflush(stdin);
                        getline(cin, descricao);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade em estoque: ";
                        cin >> qtde;
                        cout << "\nMarca: ";
                        fflush(stdin);
                        getline(cin, marca);
                        cout << "\nQuantidade(ml): ";
                        cin >> ml;
                        p = new Perfume(preco, qtde, descricao, marca, ml);
                        if (s.cadastrar(p)) {
                            cout << "\nProduto cadastrado com sucesso!\n";
                        } else {
                            cout << "\nFalha ao cadastrar o produto!\n";
                        }
                    } else {
                        cout << "\nEscolha uma opção valida\n";
                    }
                } else if (op2 == 2) {
                    vector<Produto *>::iterator p;
                    int i = 0, cod;
                    cout << "Codigo\t      Descricao\t      Valor\n";
                    cout << "\n--------------------------------------------------\n";
                    for (p = s.getProdutos()->begin(); p < s.getProdutos()->end(); p++, i++) {
                        cout << i << "\t" << (*p)->GetNome() << "\t\t" << (*p)->GetPreco() << endl;
                        cout << "\n--------------------------------------------------\n";
                    }
                    cout << "\nEntre com o Codigo do produto que deseja deletar: ";
                    cin >> cod;
                    s.getProdutos()->erase(s.getProdutos()->begin() + cod);
                    cout << "\nExcluido com Sucesso!\n";
                    cout << endl;
                } else if (op2 == 3) {
                    vector<Produto *>::iterator p;
                    Produto *prod;
                    int cod;
                    cout << "Codigo\t      Descricao\t      Valor\n";
                    cout << "\n--------------------------------------------------\n";
                    for (p = s.getProdutos()->begin(); p < s.getProdutos()->end(); p++) {
                        cout << (*p)->GetCodigo() << "\t\t" << (*p)->GetNome() << "\t\t" << (*p)->GetPreco() << endl;
                        cout << "\n--------------------------------------------------\n";
                    }
                    cout << "\nEntre com o Codigo do produto que deseja alterar: ";
                    cin >> cod;
                    if (cod != 0) {
                        for (p = s.getProdutos()->begin(); p < s.getProdutos()->end(); p++) {
                            if ((*p)->GetCodigo() == cod) {
                                prod = (*p);
                                break;
                            }
                        }
                        string desc;
                        float preco, qtde;
                        cout << "\nEntre com os dados do produto a serem mudados: ";
                        cout << "\nDescricao: ";
                        fflush(stdin);
                        getline(cin, desc);
                        cout << "\nPreco: ";
                        cin >> preco;
                        cout << "\nQuantidade: ";
                        cin >> qtde;
                        if (prod->GetTipo() == "Livro") {
                            Livro *l = static_cast<Livro*> (prod);
                            string autor, genero;
                            cout << "\nAutor: ";
                            fflush(stdin);
                            getline(cin, autor);
                            cout << "\nGenero: ";
                            fflush(stdin);
                            getline(cin, genero);

                            l->setGenero(genero);
                            l->setAutor(autor);
                            l->SetPreco(preco);
                            l->SetQuantNoEstoque(qtde);
                            l->SetNome(desc);
                        } else if (prod->GetTipo() == "Show") {
                            DVD_Show *show = static_cast<DVD_Show*> (prod);
                            string artista;
                            int musicas;
                            int ano;
                            cout << "\nArtista: ";
                            fflush(stdin);
                            getline(cin, artista);
                            cout << "\nNumero de musicas: ";
                            cin >> musicas;
                            cout << "\nAno de lançamento: ";
                            cin >> ano;

                            show->SetPreco(preco);
                            show->SetQuantNoEstoque(qtde);
                            show->SetNome(desc);
                            show->SetArtista(artista);
                            show->SetNumMusicas(musicas);
                            show->SetAno(ano);
                        } else if (prod->GetTipo() == "Software") {
                            DVD_Software *soft = static_cast<DVD_Software*> (prod);
                            string versao, requisitos;
                            int ano;
                            cout << "\nVersão: ";
                            fflush(stdin);
                            getline(cin, versao);
                            cout << "\nRequisitos: ";
                            fflush(stdin);
                            getline(cin, requisitos);
                            cout << "\nAno de lançamento: ";
                            cin >> ano;

                            soft->SetPreco(preco);
                            soft->SetQuantNoEstoque(qtde);
                            soft->SetNome(desc);
                            soft->SetVersao(versao);
                            soft->SetRequisitos(requisitos);
                            soft->SetAno(ano);
                        } else if (prod->GetTipo() == "Filme") {
                            DVD_Filme *filme = static_cast<DVD_Filme*> (prod);
                            string diretor;
                            int ano;
                            cout << "\nDiretor: ";
                            fflush(stdin);
                            getline(cin, diretor);
                            cout << "\nAno de lançamento: ";
                            cin >> ano;
                            filme->SetPreco(preco);
                            filme->SetQuantNoEstoque(qtde);
                            filme->SetNome(desc);
                            filme->SetDiretor(diretor);
                            filme->SetAno(ano);
                        } else if (prod->GetTipo() == "Perfume") {
                            Perfume *perf = static_cast<Perfume*> (prod);
                            string marca;
                            float ml;

                            cout << "\nMarca do Perfume: ";
                            fflush(stdin);
                            getline(cin, marca);
                            cout << "\nQuantidade de perfume por frasco: ";
                            cin >> ml;

                            perf->SetPreco(preco);
                            perf->SetQuantNoEstoque(qtde);
                            perf->SetNome(desc);
                            perf->setMarca(marca);
                            perf->setMl(ml);
                        } else if (prod->GetTipo() == "Relogio") {
                            Relogio *relogio = static_cast<Relogio*> (prod);
                            string marca;
                            int tipo; //true para analogico
                            cout << "\nMarca: ";
                            fflush(stdin);
                            getline(cin, marca);

                            do {
                                cout << "\nDigite o tipo: ";
                                cout << "\n1 - Analogico";
                                cout << "\n2 - Digital";
                                cin >> tipo;
                            } while (!((tipo != 1) || (tipo != 2)));

                            if (tipo == 1) {
                                relogio->setTipo(true);
                            } else {
                                relogio->setTipo(false);
                            }
                            relogio->SetPreco(preco);
                            relogio->SetQuantNoEstoque(qtde);
                            relogio->SetNome(desc);
                            relogio->setMarca(marca);
                        }
                    } else {
                        cout << "\nEscolha um codigo valido!\n";
                    }
                } else if (op2 == 4) {
                    int op3;
                    cout << "\nRelatorios:\n";
                    cout << "1 - Todos os produtos\n";
                    cout << "2 - Venda por data\n";
                    cout << "3 - Venda por codigo\n";
                    cout << "0 - Sair\n";
                    cin >> op3;
                    if (op3 == 1) {
                        vector<Produto *>::iterator p;
                        cout << "\nTodos os produtos\n";
                        cout << "Codigo\t      Descricao\t      Valor\n;";
                        cout << "\n--------------------------------------------------\n";
                        for (p = s.getProdutos()->begin(); p < s.getProdutos()->end(); p++) {
                            cout << (*p)->GetCodigo() << "\t\t" << (*p)->GetNome() << "\t\t" << (*p)->GetPreco() << "\t\t" << (*p)->GetQuantNoEstoque() << endl;
                            cout << "\n--------------------------------------------------\n";
                        }
                    } else if (op3 == 2) {
                        string data;
                        cout << "\nEntre com uma data a ser pesquisada(dd/mm/aaaa): ";
                        cin >> data;
                        vector<Venda *>::iterator v;
                        cout << "\nTodos os produtos\n";
                        cout << "Codigo\t      Descricao\t      Cliente\n ";
                        cout << "\n--------------------------------------------------\n";
                        for (v = s.getVendas()->begin(); v < s.getVendas()->end(); v++) {
                            if (data == pegaData((*v)->GetData())) {
                                cout << (*v)->GetCodigo() << "\t\t" << (*v)->GetData() << "\t\t" << (*v)->GetUsuario()->GetNome() << endl;
                                cout << "\n--------------------------------------------------\n";
                            }
                        }
                    } else if (op3 == 3) {
                        vector<Venda *>::iterator v;
                        Venda *vend;
                        int cod;
                        cout << "\nTodos os produtos\n";
                        cout << "Codigo\t      Descricao\t      Cliente\n ";
                        cout << "\n--------------------------------------------------\n";
                        for (v = s.getVendas()->begin(); v < s.getVendas()->end(); v++) {
                            cout << (*v)->GetCodigo() << "\t\t" << (*v)->GetData() << "\t\t" << (*v)->GetUsuario()->GetNome() << endl;
                            cout << "\n--------------------------------------------------\n";
                        }
                        cout << "\n\nEntre com um codigo de venda para obeter mais detalhes: ";
                        cin >> cod;
                        for (v = s.getVendas()->begin(); v < s.getVendas()->end(); v++) {
                            if (cod == (*v)->GetCodigo()) {
                                vend = (*v);
                                break;
                            }
                        }
                        cout << "\nCodigo de Venda: " << vend->GetCodigo();
                        cout << "\nData da Venda: " << pegaData(vend->GetData());
                        cout << "\nNome do cliente: " << vend->GetUsuario()->GetNome();
                        cout << "\nQuantidade de Produtos: " << vend->GetCarrinho()->getItem()->size();
                        cout << "\nValor Total: " << vend->GetValorTotalCompra();
                        cout << "\nProdutos comprados: ";
                        vector<Item *>::iterator p;
                        cout << "\nCodigo\t    Descricao\t    Valor\t    Quantidade Comprada\n";
                        cout << "\n----------------------------------------------------------\n";
                        for (p = vend->GetCarrinho()->getItem()->begin(); p < vend->GetCarrinho()->getItem()->end(); p++) {
                            cout << (*p)->GetProduto()->GetCodigo() << "\t\t" << (*p)->GetProduto()->GetNome() << "\t\t" << (*p)->GetPreco() << "\t\t" << (*p)->GetQuantidade() << endl;
                            cout << "\n--------------------------------------------------\n";
                        }
                    } else if (op3 != 0) {
                        cout << "\nEscolha uma opção valida\n";
                    }
                } else if (op2 != 0) {
                    cout << "\nEscolha uma opção valida\n";
                }
            } while (op2 != 0);
        } else if (op == 2) {
            if (s.getProdutos()->size() != 0) {
                Carrinho *cc = new Carrinho();
                Produto *prod;
                Venda *v;
                Item *it;
                int op2, y;
                float total = 0;
                Usuario *u;
                do {
                    float qtde;
                    it = new Item();
                    vector<Produto *>::iterator p;
                    cout << "\nTodos os produtos\n";
                    cout << "Codigo\t     Descricao\t     Valor\t      Quantidade\n";
                    cout << "\n--------------------------------------------------\n";
                    for (p = s.getProdutos()->begin(); p < s.getProdutos()->end(); p++) {
                        cout << (*p)->GetCodigo() << "\t\t" << (*p)->GetNome() << "\t\t" << (*p)->GetPreco() << "\t\t" << (*p)->GetQuantNoEstoque() << endl;
                        cout << "\n--------------------------------------------------\n";

                    }
                    cout << "\nDigite o codigo do produto desejado ou '0' para sair: ";
                    cin >> op2;
                    if (op2 != 0) {
                        for (p = s.getProdutos()->begin(); p < s.getProdutos()->end(); p++) {
                            if ((*p)->GetCodigo() == op2) {
                                prod = (*p);
                                break;
                            }
                        }
                        it->SetProduto(prod);
                        do {
                            cout << "\nEntre com a quantidade desejada pelo produto: ";
                            cin >> qtde;
                            if (qtde > prod->GetQuantNoEstoque()) {
                                cout << "\nQuantidade insuficiente, tente menos!";
                            }
                        } while (qtde > prod->GetQuantNoEstoque());
                        it->SetQuantidade(qtde);

                        it->SetPreco(prod->GetPreco());
                        if (cc->addItem(it)) {
                            cout << "\nAdicionado com sucesso ao carrinho\n";
                        }
                    }
                } while (op2 != 0);

                cout << "\n\t##  Carrinho  ##";
                cout << "\nFinalização da compra\nProdutos Comprados: "; //mostra todos os produtos comprados e a quantidade e pede ela pra confirmar
                //olhar se esta certo
                cout << "\nCodigo\t    Descricao\t    Valor\t     Quantidade Comprada\n";
                vector<Item *>::iterator p;
                cout << "\n--------------------------------------------------\n";
                for (p = cc->getItem()->begin(); p < cc->getItem()->end(); p++) {
                    cout << (*p)->GetProduto()->GetCodigo() << "\t\t" << (*p)->GetProduto()->GetNome() << "\t\t" << (*p)->GetProduto()->GetPreco() << "\t\t" << (*p)->GetQuantidade() << endl;
                    total += ((*p)->GetProduto()->GetPreco()*(*p)->GetQuantidade());
                    cout << "\n--------------------------------------------------\n";
                }
                cout << "\n--------------------------------------------------\n";
                cout << "Total:\t\t\t\t\t\t R$ " << total;
                cout << endl;
                do {
                    cout << "\nEstá tudo correto? ";
                    cout << "\n1 - Confirmar ";
                    cout << "\n0 - Cancelar ";
                    cin >> y;

                } while (!((y != 1) || (y != 0)));
                if (y == 1)//compra confirmada
                {
                    cout << "\nEntre com os dados do cliente e endereço pra entrega\n";
                    string nome, end, cpf, tel, nasc;
                    cout << "\nDigite seu nome: ";
                    fflush(stdin);
                    getline(cin, nome);
                    cout << "\nDigite seu endereço: ";
                    fflush(stdin);
                    getline(cin, end);
                    cout << "\nDigite seu cpf: ";
                    fflush(stdin);
                    getline(cin, cpf);
                    cout << "\nDigite seu telefone: ";
                    fflush(stdin);
                    getline(cin, tel);
                    cout << "\nDigite sua data de nascimento: ";
                    cin >> nasc;

                    u = new Usuario(nome, cpf, nasc, tel, end);

                    v = new Venda();
                    v->SetCarrinho(cc);
                    v->SetUsuario(u);
                    //--------Codigo pra pegar data
                    time_t currentTime;
                    time(&currentTime);
                    struct tm * ptm = localtime(&currentTime);
                    //-----------------------------
                    v->SetData(currentTime);
                    //valor da compra
                    v->setValorTotalCompra(total);
                    int v2 = rand() % 12 + 1;
                    float frete = total * (v2 / 100);
                    v->setValorFrete(frete);

                    s.addVenda(v);
                    cout << "\nVenda Concluida!! \n";

                } else {
                    cout << "\nCompra Cancelada!!\n";
                }
            } else {
                cout << "\nNão existem itens cadastrados para serem comprados!\n";
            }
        } else if (op != 0) {
            cout << "\nEscolha uma opção valida\n";
        }
    } while (op != 0);
    cout << "\nVoce saiu!\n";
    salva(&s);
    return 0;
}