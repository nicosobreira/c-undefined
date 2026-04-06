# Undefined Behaviour

Um **comportamento indefinido** é quele cujo o *standard* não **impõem** nada sobre seu resultado. Note que é diferente de dizer que o *standard* impões um resultado entre alguns especificados.

O comportamento indefinido existe devido ao momento no qual a linguagem C nasce. Naquela época, existia uma diferença gigantesca entre modelos de computadores e no modo com que eles definiam certas operações, regras e **falhas**. E principalmente como tornar o código seguro tinha seus pontos negativos mais acentuados, defino a performance dos computadores em geral (Veja [Vantagens](#vantagens)).

## Vantagens

A principal vantagem são as possíveis **otimizações** que podem ser feitas. Por exemplo, se o C definisse `INT32_MAX + 1` como uma operação proibida, uma conta simples para inteiros i e j como `i = j + 10` **sempre** verificaria se `j = INT32_MAX - 10 + 1`.

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

O acesso `array[size]` é indefinido, e por isso o compilador não precisa verificar se para todo acesso à um array o endereço é válido.

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
Sendo assim, dependo do compilado, ele pode: **assumir** que `p != NULL`, substituindo `p == NULL` por `false`; ou **assumir** que `p == NULL` é um possível valor para `p`, e por isso **eliminar** a causa da indefinição `++(*p)` da função `f`.

## Referências

- [
Undefined Behavior in C++: What Every Programmer Should Know and Fear - Fedor Pikus - CppCon 2023](https://www.youtube.com/watch?v=k9N8OrhrSZw)
- [Undefined Behavior in C++: What is it, and why do you care?](https://www.youtube.com/watch?v=uHCLkb1vKaY)
- [Undefined Behavior in C++: A Performance Viewpoint - Fedor Pikus - CppNow 2022](https://www.youtube.com/watch?v=BbMybgmQBhU)
- [What Every C Programmer Should Know About Undefined Behavior #1/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html)
# c-undefined
