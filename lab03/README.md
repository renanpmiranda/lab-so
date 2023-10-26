*LABORATÓRIO DE SISTEMAS OPERACIONAIS - PTHREADS PARTE 1*

Lucas Eleutério da Silva - TIA 32240597

Renan Pires de Miranda - TIA 32248253
  
  1.  Execução da instância AWS e instalação do git no terminal:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/bc2631a4-7bb1-4b9d-80af-e12ffdbab2c9)

  2.  Geração da chave SSH e clonagem do repositório:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/1e786d08-9cb2-41cb-bfa8-2fc132cfc889)

  3.  Criação do arquivo para o exercício dentro da pasta 'lab03':

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/d9f8ba4a-698b-40d4-8d4c-00871f82a6f5)

   - Código desenvolvido:
    
   ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/0f03b4b4-f179-437b-8cb0-6cdba49772c6)
   ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/82acd67b-c915-49ca-acc3-3086cc1e2b53)
   ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/721917d4-880e-4bed-9894-4477479b6214)

  4.  Envio do arquivo criado para staging area, realização do commit e do push ao repositório:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/b7243184-cbba-465b-a88f-ac69ed8a6915)

  5.  Instruções para compilação e execução do código:
     
  - Compilação:
    
Use o compilador gcc para compilar o código. O código utiliza a biblioteca pthread para threads, então é necessário incluir a flag -lpthread:

    gcc nome_do_arquivo.c -o nome_do_programa -lpthread

  - Execução:

Para executar o programa, você precisa especificar o número de threads como argumento. Por exemplo, para executar o programa com 4 threads:

    ./nome_do_arquivo 4

   6. Demonstração do código em funcionamento:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/4eb541d3-8255-479e-9c1e-c2c8ecf6e577)

  
