<!-- TODO:  -->
# Aulas da disciplina Laboratório de Introdução à Programação Paralela 
### Ementa: Práticas em laboratório para introdução aos conceitos básicos de programação paralela. Modelos e ambientes para programação paralela. Corretude da execução concorrente em sistemas de memória compartilhada. Técnicas de paralelização. Algoritmos paralelos. Avaliação de desempenho em computação paralela. 

### Profiling ###

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
  
Do livro: 
Em muitos casos, uma parte relativamente pequena de seu software é responsável pela maior parte do déficit de desempenho e escalabilidade. No entanto, identificar os gargalos reais podem ser difícil sem uma ferramenta adequada. Por exemplo, no caso de um alocador de buffer do kernel, toda a atenção se concentrou na busca de um array denso que acabou representando apenas alguns por cento do tempo de execução do alocador. Um perfil de execução coletado por meio de um analisador lógico focou a atenção nas falhas de cache que eram realmente responsáveis **pela maior parte do problema [MS93]**. Um método antigo, mas bastante eficaz, de rastrear bugs de desempenho e escalabilidade é executar o programa em um depurador e, em seguida, interrompê-lo periodicamente, registrando as pilhas de todos os threads em cada interrupção. A teoria aqui é que, se algo está atrasando o seu programa, ele deve estar visível nas execuções dos seus threads. Dito isso, há uma série de ferramentas que normalmente farão um trabalho muito melhor de ajudar você a focar sua atenção onde ela fará mais bem. Duas escolhas populares são gprof e perf. Para usar perf em um programa de processo único, prefixe seu comando com o registro perf e, depois que o comando for concluído, digite o relatório perf. Há muito trabalho em ferramentas para depuração de desempenho de programas multiencadeados, o que deve facilitar esse trabalho importante. Pontos de partida: 

https://www.embarcados.com.br/desempenho-gnu-profiler-gprof/
https://stackoverflow.com/questions/6328673/which-is-the-most-reliable-profiling-tool-gprof-or-kcachegrind
https://www.thegeekstuff.com/2012/08/gprof-tutorial/
http://gernotklingler.com/blog/gprof-valgrind-gperftools-evaluation-tools-application-level-cpu-profiling-linux/
https://perf.wiki.kernel.org/index.php/Tutorial#Benchmarking_with_perf_bench
