times = []
# esse código cria uma lista de dicionários
def cria_time(nome):
    time = { 'nome' : nome,
             'pt' : 0,
             'jg' : 0,
             'gp' : 0,
             'gc' : 0,
             'vit' : 0,
             'emp' : 0,
             'der' : 0 ,
	     'sg' : 0
            }
    return time
def imprime_tabela(times):
    print ('Times        | P | J | V | E | D | GP | GC | SG')
    for time in times:
        print ("{:<13} {:>2d} {:>3d} {:>3d} {:>3d} {:>3d} {:>4d} {:>4d} {:>4d} ".format(time['nome'], time['pt'], time['jg'],time['vit'],time['emp'],time['der'],time['gp'],time['gc'],time['sg']))

def troca(lista,var,i,j):
	aux = lista[j][var]
	lista[j][var] = lista[i][var]
	lista[i][var] = aux

def trocastr(lista,var,i,j):
	aux = ''
	aux = lista[j][var]
	lista[j][var] = lista[i][var]
	lista[i][var] = aux


def ordenacao(times):
    for i in range(0,len(times)-1):
       men = i
       for j in range(i+1,len(times)):
           if (times[j]['pt'] >= times[men]['pt']):
               if (times[j]['pt'] == times[men]['pt']):
                   if (times[j]['vit'] >= times[men]['vit']):
                       if (times[j]['vit'] == times[men]['vit']):
                           if (times[j]['gp'] >= times[men]['gp']):
                               if (times[j]['gp'] == times[men]['gp']):
                                   if (times[j]['sg'] >= times[men]['sg']):
                                       if (times[j]['sg'] == times[men]['sg']):
                                           if (times[j]['nome'] < times[men]['nome']):
                                               men = j
                                       else:
                                           men = j
                                   else:
                                       continue
                               else:
                                    men = j
                           else:
                               continue
                       else:
                           men = j
                   else:
                       continue
               else:
                   men = j
           else:
               continue
       trocastr(times,'nome',men,i)
       troca(times,'gp',men,i)
       troca(times,'gc',men,i)
       troca(times,'vit',men,i)
       troca(times,'emp',men,i)
       troca(times,'der',men,i)
       troca(times,'sg',men,i)
       troca(times,'jg',men,i)
       troca(times,'pt',men,i)






arquivo = open("times3.txt",'r')
for i in range(20): 
    nome = arquivo.readline().strip() # readline lê uma linha do arquivo, strip tira os espaços em branco
    times.append(cria_time(nome))
arquivo.close()
ordenacao(times)

imprime_tabela(times)
 


