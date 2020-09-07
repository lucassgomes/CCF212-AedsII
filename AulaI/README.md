## Aula prática 1

### Descrição:
Implementar, em linguagem C, os algoritmos de inserção e
percursos (em ordem, pré-ordem e pós-ordem) em uma árvore BST.
Baseado nos [algoritmos do Livro Texto da disciplina.](http://www2.dcc.ufmg.br/livros/algoritmos/)

### Dicas iniciais:
Cada nó representa uma estrutura com: a chave e os ponteiros para as sub-árvores esquerda e direita.
```
typedef struct nodeType *pointerType;
typedef struct nodeType {
    int information;
    pointerType left, right;
} nodeType;
```
Função que cria uma árvore vazia(raiz nula).
```
void initializeTree(pointerType *rootPointer) {
    *rootPointer = NULL;
}
```