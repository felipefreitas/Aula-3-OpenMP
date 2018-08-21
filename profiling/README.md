<!-- TODO:  -->
# Aulas da disciplina Laboratório de Introdução à Programação Paralela 
### Ementa: Práticas em laboratório para introdução aos conceitos básicos de programação paralela. Modelos e ambientes para programação paralela. Corretude da execução concorrente em sistemas de memória compartilhada. Técnicas de paralelização. Algoritmos paralelos. Avaliação de desempenho em computação paralela. 

### Profiling ###
In many cases, a fairly small portion of your software is responsible for the majority of the performance and scalability shortfall. However, developers are notoriously unable to identify the actual bottlenecks by hand. For ex- ample, in the case of a kernel buffer allocator, all attention focused on a search of a dense array which turned out to represent only a few percent of the allocator’s execution time. An execution profile collected via a logic analyzer focused attention on the cache misses that were actually responsible for the majority of the problem [MS93].
An old-school but quite effective method of tracking down performance and scalability bugs is to run your program under a debugger, then periodically interrupt it, recording the stacks of all threads at each interruption. The theory here is that if something is slowing down your program, it has to be visible in your threads’ executions.
That said, there are a number of tools that will usually do a much better job of helping you to focus your atten- tion where it will do the most good. Two popular choices are gprof and perf. To use perf on a single-process program, prefix your command with perf record, then after the command completes, type perf report. There is a lot of work on tools for performance debugging of multi-threaded programs, which should make this impor- tant job easier. Again, one good starting point is Brendan Gregg’s blog.15

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
https://www.embarcados.com.br/desempenho-gnu-profiler-gprof/
https://stackoverflow.com/questions/6328673/which-is-the-most-reliable-profiling-tool-gprof-or-kcachegrind
https://www.thegeekstuff.com/2012/08/gprof-tutorial/
http://gernotklingler.com/blog/gprof-valgrind-gperftools-evaluation-tools-application-level-cpu-profiling-linux/
https://perf.wiki.kernel.org/index.php/Tutorial#Benchmarking_with_perf_bench
