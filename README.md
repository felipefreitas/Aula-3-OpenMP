<!-- TODO:  -->
# Aulas da disciplina Laboratório de Introdução à Programação Paralela 
### Ementa: Práticas em laboratório para introdução aos conceitos básicos de programação paralela. Modelos e ambientes para programação paralela. Corretude da execução concorrente em sistemas de memória compartilhada. Técnicas de paralelização. Algoritmos paralelos. Avaliação de desempenho em computação paralela. 

Aula baseada nos slides em https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf. 

[O arquivo ](./OpenMP-4.0-C.pdf) contém uma Quick Reference Card de OpenMP 4.0.

A maior parte dos cõdigos entregues na aula anterior tinham um erro que gerava execuçòes incorretas: 

```cpp
#pragma omp parallel
	  {
	  	double partial = 0.0;
	  	#pragma omp for
			for (i=1;i<= num_steps; i++){
			  x = (i-0.5)*step;
			  partial += 4.0/(1.0+x*x);
			}
            ...
 ```           
O erro está no uso da variável compartilhada x sem proteção por todas as threads dentro da região paralela. Para entender o problema, vamos estudar o ambiente de dados em OpenMP.

```cpp
void simple(int n, float *a, float *b)
{
int i;
#pragma omp parallel for
    for (i=1; i<n; i++) /* i is private by default */
}

```

https://ava.cefetmg.br/pluginfile.php/8569/mod_resource/content/1/Intro_To_OpenMP_Mattson.pdf
