# SO_Grupo4_LeoFraga
Repositório SO 04N11. Integrantes do Grupo: Leonardo Fraga TIA: 32158841 

Lab03_Threads02:
    a-)A implementação paralela com múltiplas threads, pode haver divergências na ordem de execução das threads, resultando em diferentes ordens de soma dos termos da série de Leibniz. Isso pode levar a pequenas variações nos resultados, mas geralmente os resultados obtidos com mais threads tendem a ser mais precisos devido à divisão do trabalho entre as threads.
    b-)Na solução sem mutex, cada thread tinha sua própria cópia da variável "sum" e a atualização era feita localmente. Isso pode levar a um erro, pois duas threads podem estar atualizando "sum" ao mesmo tempo, o que pode resultar em uma leitura incorreta do valor final.
    Já na solução com mutex, a exclusão mútua é garantida com o uso da variável mutex. Apenas uma thread pode bloquear o mutex e atualizar "sum" por vez, evitando condições de corrida e garantindo que o valor final de "sum" seja o correto.
