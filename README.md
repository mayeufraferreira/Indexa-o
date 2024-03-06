# Projeto de Indexação
![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=dark&style=for-the-badge)

## Tecnologias Utilizadas
<img align="center" alt="mayeufraferreira-C" height="50" width="50" src="https://github.com/devicons/devicon/blob/master/icons/c/c-plain.svg">

## Descrição
Códigos referentes ao projeto de implementação de indexação para a disciplina de Algoritmos e Estruturas de Dados II da Universidade Federal do Agreste de Pernambuco (UFAPE).

## Instruções
Implemente a lógica interna de funcionamento de um Sistema Gerenciador de Banco de Dados (SGBD), aplicado para gerenciar os dados de apenas uma tabela, utilizando a técnica de indexação, de acordo com as definições a seguir:
+ A tabela deve armazenar registros que contêm pelo menos 5 campos. A definição do registro/campos a serem gerenciados é de livre escolha, desde que seja algo adequado ao ambiente acadêmico;
+ Os campos do tipo string devem ter alocação estática (com tamanho máximo predefinido);
+ Utilize três índices na tabela: um índice BST, um AVL e um RB, cada um em um campo diferente;
+ Os dados dos registros devem ser armazenados em um arquivo binário sequencial, conforme exemplificado no projeto "arquivo 3";
+ Cada índice deve ser salvo em um arquivo próprio, conforme exemplificado no projeto "arquivo 1". OBS: durante a execução do programa, os índices devem ser mantidos em memória RAM, sendo passados para o arquivo apenas quando o usuário escolher a opção "sair" do programa;
+ Implemente a função de adicionar registro, a qual insere o registro no arquivo de dados e atualiza os três índices;
+ Implemente a função de remover registro, que remove apenas as referências ao registro nos índices, sem a necessidade de modificar o arquivo de dados;
+ Implemente uma função de busca para cada índice. Esta função deve imprimir na tela todos os dados satélite do registro referenciado pelo índice passado como parâmetro;
+ Implemente uma função para exibir os registros ordenados de acordo com cada um dos índices (inorder);
+ Implemente a função main que permite ao usuário utilizar o sistema com todas as opções de funções implementadas;
+ Ponto extra: Implemente uma tabela de relocação, que mantém o registro de cada elemento excluído para reutilizar o espaço no arquivo de dados em futuras inserções;
+ Ponto extra: Acrescente ao menos um campo string de tamanho variável. A forma de manipulação no arquivo de dados precisará adotar alguma estratégia de separação de campos e registros, por exemplo, formato XML, JSON, caractere separador, etc. Certifique-se de implementar a alocação dinâmica de memória para armazenar as strings de tamanho variável. Além disso, explique e implemente uma estratégia adequada para a manipulação desses campos, como o uso de delimitadores ou formatos de serialização (XML, JSON, etc.), garantindo a integridade dos dados ao ler e gravar no arquivo de dados. É importante observar que essa funcionalidade também terá impactos na implementação da tabela de relocação de dados. A parte referente ao gerenciamento de strings de tamanho variável na memória RAM está exemplificado no projeto "arquivo 2";
