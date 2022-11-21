#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct pessoa{
  string email;
  string nome;
  string senha;
};

int main(int argc, char** argv){
  int choice;
  int x = 0;
  setlocale(LC_ALL,"");
  pessoa *v[20];
  for(int i = 0; i < 21; i++){
    v[i] = NULL;
  }
  inicio:
  cout << "\nBem Vindo(a) ao sistema de cadastro!\nSe você deseja cadastrar alguem, digite: 0\nSe você deseja consultar um cadastro pelo nome, digite: 1\nSe você deseja excluir um cadastro pelo nome, digite: 2\nSe você deseja gerar um arquivo texto dos dados cadastrados, digite 3\nSe você deseja encerrar o programa, digite 4\n(Você pode cadastrar até 20 pessoas)\n\n";
  cin >> choice;
  while(choice != 4){
    while(choice > 6 && choice < 0){
      cout << "\nPor favor digite um valor válido\n";
      cin >> choice;
    }
    if(choice == 0){
      v[x] = new pessoa;
      cout << "\n Digite o nome: ";
      cin >> v[x]->nome;
      
      cout << "\n Digite o email: ";
      cin >> v[x]->email;
     
      cout << "\n Digite a senha: ";
      cin >> v[x]->senha;
      cout << "\n";
      x++;
      cout << "\n Se deseja cadastrar outra pessoa digite: 0";
      cout << "\n Se deseja voltar ao inicio digite: 5\n\n";
      cin >> choice;
      if(choice == 5){
        goto inicio;
      }
      
    }
    else if(choice == 1){
       string test;
       cout << "\n  Digite o nome da pessoa que você deseja procurar"<< endl;
       cin >> test;
      for(int i = 0; i < x; i++){
        if(test == v[i]->nome){
          cout << "\n As informações cadastradas são:\nNome: " << v[i]->nome << "\nEmail: " << v[i]->email << "\n Senha: " << v[i]->senha << endl;
        }
        else
          cout << "\n Não foi possível encontrar a pessoa cadastrada" << endl;
      }
      cout << "\n Se deseja encontrar outra pessoa digite: 1";
      cout << "\n Se deseja voltar ao ínicio digite: 5\n\n";
      cin >> choice;
      if(choice == 5){
        goto inicio;
      }
    }
    else if(choice == 2){
    string test;
    pessoa *aux;
      for(int q = 0; q < x; q++){
       cout << v[q]->nome << " " << v[q]->email << " " << v[q]->senha << endl;  
      }
       cout << "\n Digite o nome da pessoa que voce deseja excluir: "<< endl;
       cin >> test;
      for(int i = 0; i < x; i++){
        if(test == v[i]->nome){
          cout << "\n A pessoa foi excluÃ­da com sucesso"<< endl;
          if (i == (x-1)){
            v[i] = NULL;
          }else{
            aux = v[i]; 
            v[i] = v[x-1];
            v[x-1] = NULL;          
          }      
        }
        else
          cout << "\n Não foi possÃ­vel encontrar a pessoa cadastrada" << endl;
      }
      for(int q = 0; q < x; q++){
       cout << v[q]->nome << " " << v[q]->email << " " << v[q]->senha << endl;  
      }
      cout << "\n Se deseja excluir outra pessoa digite: 2";
      cout << "\n Se deseja voltar ao inicio digite: 5\n\n";
      cin >> choice;
      if(choice == 5){
        goto inicio;
      }
    }
    else if(choice == 3){
      cout << "\n Seu arquivo foi criado" << endl;
      ofstream myfile("Cadastros.txt");
      if(myfile.is_open()){
          myfile << "Nome/Email/Senha" << endl;
        for(int i = 0; i < x; i++){
          myfile << v[i]->nome << " ";
          myfile << v[i]->email << " ";
          myfile << v[i]->senha << endl;
        }
      }
       myfile.close();
        
      
      cout << "\n Se deseja recriar o arquivo digite: 3";
      cout << "\n Se deseja voltar ao inicio digite: 5\n\n";
      cin >> choice;
      if(choice == 5){
        goto inicio;
      }
    }
    }
 return 0;
}
