<!-- TODO:  -->
# Aulas da disciplina Laboratório de Introdução à Programação Paralela 
### Ementa: Práticas em laboratório para introdução aos conceitos básicos de programação paralela. Modelos e ambientes para programação paralela. Corretude da execução concorrente em sistemas de memória compartilhada. Técnicas de paralelização. Algoritmos paralelos. Avaliação de desempenho em computação paralela. 

Aula baseada nos slides em https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf. [O arquivo ](./OpenMP-4.0-C.pdf) contém uma Quick Reference Card de OpenMP 4.0.

A maior parte dos cõdigos entregues na aula anterior tinham um erro que gerava execuçòes incorretas: o valor de Pi era diferente em cada execução. 

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
O erro está no uso da variável compartilhada **x** sem proteção por todas as threads dentro da região paralela. Para entender o problema, vamos estudar o ambiente de dados em OpenMP.

```cpp
void simple(int n, float *a, float *b)
{
int i;
#pragma omp parallel for
    for (i=1; i<n; i++) /* i is private by default */
}

```

Insert the appropriate OpenMP directives in the

files 
2. Analyse the code performance and plot the speedup curves o
btained.
3. Repeat this but use the
DYNAMIC
distribution mode of the iterations. Propose
an explanation for the difference in performance observed.

https://ava.cefetmg.br/pluginfile.php/8569/mod_resource/content/1/Intro_To_OpenMP_Mattson.pdf

Profiling
Extração do perfil da execução de um programa 
Pode incluir, por exemplo: 
Tempo gasto na execução do programa inteiro e de cada subprograma 
Número de chamadas de funções ou métodos 
Grafo de chamadas: Diagrama espaço-tempo (diagrama de Gantt) 
Técnica: Instrumentação 
  adição de instruções no programa para coleta de dados sobre a execução 
  pode ser muito intrusiva 
  mais precisa 
Técnica: Amostragem 
  interrupção periódica do programa para coleta de dados sobre a execução 
  tende a ser pouco intrusiva 
  menos precisa 

Afinidade
Thread affinity restricts execution of certain threads (virtual execution units) to a subset of the physical processing units in a multiprocessor computer. Depending upon the topology of the machine, thread affinity can have a dramatic effect on the execution speed of a program.
This minimizes thread migration and context-switching cost among cores. It also improves the data locality and reduces the cache-coherency traffic among the cores (or processors).
The Intel® OpenMP* runtime library has the ability to bind OpenMP threads to physical processing units. The interface is controlled using the KMP_AFFINITY environment variable

