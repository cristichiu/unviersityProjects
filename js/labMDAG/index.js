const puncte = [1,2,3,4,5,6,7,8]
const muchii = [[1,2], [2,3], [5,6], [3,5], [1,7], [4,8], [4,5]]
const matriceDeIncidenta = []
const formaAlgebricaGrafMuchii = []
for(let i=0; i<puncte.length; i++) {
    const coloana = []
    for(let j=0; j<muchii.length; j++) {
        coloana.push(0)
    }
    matriceDeIncidenta.push(coloana)
}

for(let i=0; i<muchii.length; i++) {
    matriceDeIncidenta[muchii[i][0]-1][i] = 1
    matriceDeIncidenta[muchii[i][1]-1][i] = 1
}

for(let i=0; i<matriceDeIncidenta.length; i++) {
    let st = null
    for(let j=0; j<matriceDeIncidenta[i].length; j++) {
        if(matriceDeIncidenta[i][j]) {
            if(st == null) st = j+1; else {
                formaAlgebricaGrafMuchii.push([st, j+1])
                st = j+1
            }
        }
    }
}

let str = "";
for(let i=0; i<puncte.length; i++) {
    for(let j=0; j<muchii.length; j++) {
        str += matriceDeIncidenta[i][j] + " "
    }
    str += "\n"
}
console.log("Muchii: ", muchii)
console.log("Matrice de incidenta: \n" + str)
console.log("Forma algebrica graf muchii: ", formaAlgebricaGrafMuchii)

function DFS(vs, matDeInc) {
    const n = matDeInc.length;
    const flaguri = new Array(n).fill(0);
    const parcurgere = [];
    let current = vs;

    while(true) {
        if(flaguri[current-1] === 0) {
            flaguri[current-1]++;
            parcurgere.push(current);
        }
        let vecini = false;
        for(let i=0; i<matDeInc[current - 1].length; i++) {
            if(matDeInc[current - 1][i]) {
                for(let j=0; j<n; j++) {
                    if(matDeInc[j][i] && flaguri[j] === 0) {
                        current = j + 1;
                        vecini = true;
                        break;
                    }
                }
            }
            if(vecini) break
        }
        if(!vecini) {
            flaguri[current - 1] = 2;
            if (current === vs) break;
            for (let i = parcurgere.length - 1; i >= 0; i--) {
                if (flaguri[parcurgere[i] - 1] === 1) {
                    current = parcurgere[i];
                    break;
                }
            }
        }
    }

    console.log("Flaguri:", flaguri);
    console.log("Parcurgere DFS:", parcurgere);
}
DFS(2, matriceDeIncidenta)



/*
 * Punctu 5
a. Exista grafuri neorientate pentru care gradele varfurilor sunt distincte 2 cate 2.

Daca am avea un graf din n puncte. Atunci fiecare punct ar trebui sa aiba grade de la 0 la n-1, (fiecare grad aparand o singura data) deoarece gradul maxim ar fi n-1 si din cauza ca avem n puncte trebui sa-l includem si pe 0. Dar punctul cu gradul maxim ar fi conectat la fiecare punct, deci ar fi imposibil sa existe un punct cu gradul 0. Afirmatia este falsa.
b. Pentru orice graf neorientat, numarul varfurilor de ordin impar este par.

Fiecare muchie intr-un graf neorientat o sa fie incident la 2 puncte deci putem zice ca indiferent de cate muchii avem numarul varfurilor o sa fie egal cu 2m unde m este nr de muchii. Daca avem puncte cu grad impar si adunam gradele intre ele o sa optinem un nr par deoarece conditia 2m se aplica in orice caz. nr par * nr impar = nr par, nr par * nr par = nr par.

 * Punctul 10
Fie Gn un graf neorientat, varfurile caruia reprezinta primele n numere naturale {1, 2 ...n } doua varfuri x, y sunt adiacente, daca si numai daca numerele x si y sunt reciproc prime.
a. Sa se scrie matricea de adiacenta a grafurilor G5, G6, G7. Care este structura matricei de adiacenta a grafului Gn?
b. Sa se verifice daca graful Gn este conex.
c. Sa se demonstreze ca Gm, m<n este subgraf al grafului Gn, generat de submultimea de varfuri {1, 2, ... m }

a:
(1, 2, 3, 4, 5)
(1, 2) (1, 3) (1, 4) (1, 5) (2, 3) (2, 5) (3, 4) (3, 5) (4, 5)
0 1 1 1 1
1 0 1 0 1
1 1 0 1 1
1 0 1 0 1
1 1 1 1 0

(1, 2, 3, 4, 5, 6)
(1, 2) (1, 3) (1, 4) (1, 5) (1, 6) (2, 3) (2, 5) (3, 4) (3, 5) (4, 5) (5, 6)
0 1 1 1 1 1
1 0 1 0 1 0
1 1 0 1 1 0
1 0 1 0 1 0
1 1 1 1 0 1
1 0 0 0 1 0

(1, 2, 3, 4, 5, 6, 7)
(1, 2) (1, 3) (1, 4) (1, 5) (1, 6) (1, 7) (2, 3) (2, 5) (2, 7) (3, 4) (3, 5) (3, 7) (4, 5) (4, 7) (5, 6) (5, 7) (6, 7)
0 1 1 1 1 1 1
1 0 1 0 1 0 1
1 1 0 1 1 0 1
1 0 1 0 1 0 1
1 1 1 1 0 1 1
1 0 0 0 1 0 1
1 1 1 1 1 1 0

Matricea de adiacenta este simetrica si patratica, iar A(ij) o sa fie 1 doar daca punctu i si punctu j sunt reciproc prime, adica divizorul lor comun este doar 1. Diagonala principala este 0, iar primul rand si prima coloana o sa fie mereu 1 inafara de unde i=j

b:
Gn o sa fie un graf conex deoarece cel putin punctul 1 o sa fie adiacent cu toate restu punctelor, deci prin punctu 1 o sa poti ajunge oriunde si de oriunde o sa poti ajunge in punctu 1. Este clar ca o sa existe si alte lanturi care o sa ne duca dintr-un punct in altul, dar prin punctu 1 o sa demonstram ca Gn indiferent de n graful o sa fie mereu conex, deoarece punctu 1 conecteaza fiecare punct datorita naturii acestui graf.

c:
Un subgraf se optiune prin alegerea unui subset de varfuri si muchii, iar {1, 2, ..., m} este un subset de varfuri din {1, 2, ..., n} deci formeaza un subgraf al grafului Gn avand in vedere ca m<n
*/
