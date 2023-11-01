*LABORATÓRIO DE SISTEMAS OPERACIONAIS - PTHREADS PARTE 2*

Lucas Eleutério da Silva - TIA 32240597

Renan Pires de Miranda - TIA 32248253

  1.  Execução da instância AWS e instalação do git no terminal:
     
  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/f9c5ef73-fafe-4abf-ba0a-80f019046779)

  2.  Geração da chave SSH e clonagem do repositório:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/dfe4c8cb-9149-4136-8334-c256fbe7e745)

  3.  Criação dos arquivos com cada uma das implementações dentro da pasta 'lab04':

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/f569abcb-59ff-46ef-8789-90ee77bba5d7)

  - Implementação sem Mutex:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/3792ad6f-4b3f-4552-814f-d2f8304adec2)
  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/396aa08c-524c-4479-b961-9a2aeeb0d337)

  - Implementação com Mutex:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/72b01a20-f4fe-432d-85c2-23ca24e2b487)
  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/e607c1bf-4ed3-4c6f-82ed-9bca33f52fa3)

  4.  Envio dos arquivos criados para staging area, realização do commit e push ao repositório:
  
  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/b59807bd-3a48-47c9-b87f-14d53ca35387)

  5. Instruções para compilação e execução do código:

  - Compilação:
    
Use o compilador gcc para compilar o código. O código utiliza a biblioteca pthread para threads, então é necessário incluir a flag -lpthread:

    gcc nome_do_arquivo.c -o nome_do_programa -lpthread

  - Execução:

Para executar o programa, basta especificar a rota para o arquivo a ser executado. Por exemplo:

    ./nome_do_arquivo

  6.  Demonstração do código em funcionamento:

  - Implementação sem Mutex:    

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/343763d1-7d2c-41ee-bb15-c041bc1ca3c4)

  - Implementação com Mutex:

  ![image](https://github.com/renanpmiranda/lab-so/assets/111312320/86df7290-c982-4fe5-ae2a-0041471abc7c)

  7.  Diferenças entre as Implementações sem e com Mutex:

  A diferença fundamental entre as implementações sem e com mutex está na forma como as threads interagem com a variável de soma (sum) que acumula a estimativa de π. Abaixo está uma análise detalhada das duas abordagens:

  - Implementação sem Mutex:
    
Isolamento de cálculo: Cada thread calcula uma parte da série de forma independente e armazena seu resultado em uma variável local. Ao final de seu cálculo, cada thread armazena sua soma parcial em um array global partial_sum indexado pelo seu rank.

Ausência de contenção: Como cada thread tem sua própria seção do array partial_sum, não há risco de duas ou mais threads tentarem atualizar o mesmo local de memória ao mesmo tempo. Isso elimina a necessidade de sincronização e pode levar a uma execução mais rápida em comparação com a implementação com mutex, dependendo do cenário.

Combinação de resultados: Após todas as threads terem completado sua execução, a thread principal (normalmente a thread 0) combina os resultados parciais armazenados no array partial_sum para obter a estimativa final de π.

  - Implementação com Mutex:
    
Soma Global Compartilhada: Existe uma variável global sum que todas as threads atualizam simultaneamente. Como várias threads podem tentar atualizar esta variável ao mesmo tempo, há um risco de condições de corrida.

Sincronização com Mutex: Para evitar condições de corrida, a atualização da variável global sum é protegida por um mutex. Quando uma thread deseja adicionar à sum, ela bloqueia o mutex, realiza a adição e, em seguida, libera o mutex. Isso garante que apenas uma thread possa atualizar a sum de cada vez.

Contenção e Sobrecarga: Embora o mutex evite condições de corrida, ele introduz contenção. Sempre que uma thread bloqueia o mutex, outras threads que desejam atualizar a sum devem esperar. Além disso, o bloqueio e desbloqueio do mutex têm sua própria sobrecarga. Isso pode tornar a implementação com mutex mais lenta, especialmente quando o número de threads é alto e/ou os cálculos realizados entre atualizações são relativamente pequenos.

  - Conclusão:
    
A versão sem mutex é geralmente mais rápida porque evita a sobrecarga e contenção associadas ao uso de mutex. No entanto, ela requer uma estrutura de dados adicional (o array partial_sum) e uma etapa adicional para combinar os resultados parciais.


    

