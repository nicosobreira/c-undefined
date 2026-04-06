# Comportamento Indefinido em C

Um **comportamento indefinido** é aquele cujo o *standard* não **impõem** nada sobre seu resultado. Isso implica dizer que: **não existem resultados errados, tudo pode acontecer**.

O comportamento indefinido existe devido ao momento no qual a linguagem C nasce. Naquela época, existia uma diferença gigantesca entre modelos de computadores e no modo com que eles definiam certas operações, regras e **falhas**. E principalmente como tornar o código seguro tinha seus pontos negativos mais acentuados, devido a performance dos computadores em geral (Veja [Vantagens](#vantagens)).

## Vantagens

A principal vantagem são as possíveis **otimizações** que podem ser feitas. Por exemplo, se a linguagem C definisse `INT32_MAX + 1` como uma operação inválida, uma conta simples para inteiros i e j como `i = j + 10` **sempre** verificaria se `j = INT32_MAX - 10 + 1`.

Outro exemplo está no código a seguir:

```c
#include <stdio.h>

int main(void)
{
	const int size = 3;
	int array[size] = {0, 9, 8};

	printf("%d\n", array[size]);

	return 0;
}
```

O acesso ao elemento `array[size]` está fora dos limites, e portanto é indefinido. Por isso o compilador não precisa verificar se para todo acesso à um array em algum index é válido.

## Qual é o problema real?

Basta apenas **uma operação indefinida** para que o **programa inteiro** seja indefinido.
Exemplo na função f

```c
int f(int *p)
{
	++(*p);

	if (p == NULL)
	{
		return 0;
	}

	return *p;
}
```

Um programador amador olharia para o código e diria: "Essa função é completamente segura, já que ele verifica se `p == NULL`!", mas note que a verificação ocorre **depois** de `++(*p)`, ou seja, depois que o valor do ponteiro é acessado. No caso em que `p == NULL`, ocorre o acesso de um valor de um ponteiro nulo, ou seja, um comportamento indefinido.
Sendo assim, dependendo das otimizações aplicadas pelo compilador, ele pode: **assumir** que `p != NULL`, substituindo `p == NULL` por `false`; ou **assumir** que `p == NULL` é um possível valor para `p`, e por isso **eliminar** a causa da indefinição `++(*p)` da função `f`.

## Tipos

- *Signed integer overflow*, quando `INT32_MAX + 1`
- *Dereferencing a `NULL` pointer*
- Leitura de variáveis não iniciadas

## Referências

- [Undefined Behavior in C++: What Every Programmer Should Know and Fear - Fedor Pikus - CppCon 2023](https://www.youtube.com/watch?v=k9N8OrhrSZw) => Palestra explicando UB e suas implicações práticas
- [Undefined Behavior in C++: What is it, and why do you care?](https://www.youtube.com/watch?v=uHCLkb1vKaY) => Introdução ao conceito de UB para programadores
- [Undefined Behavior in C++: A Performance Viewpoint - Fedor Pikus - CppNow 2022](https://www.youtube.com/watch?v=BbMybgmQBhU) => Como UB influencia otimizações do compilador
- [What Every C Programmer Should Know About Undefined Behavior #1/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html) => Artigo do LLVM sobre UB
