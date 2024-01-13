Progetto finale per l'insegnamento "Laboratorio di Programmazione" per l'A.A. 2023/24
Gruppo: cpp(coders per passione)
Collaboratori: Manuel Andretto, Lorenzo Nardin, Marco Spolverato

Descrizione del progetto:

main: crea un oggetto della classe Game, che riceve nel costruttore tre oggetti di tipo ComputerPlayer e uno di tipo HumanPlayer/ComputerPlayer in base al comando inserito dall'utente sulla riga di comando; fa inoltre partire il gioco tramite un'opportuno metodo game()

Game: classe che gestisce le dimaniche di gioco, in particolare fa in modo che le regole vengano rispettate e contiene opportune funzioni per la gestione del gioco

Player: classe base che contiene le caratteristiche comuni a tutti i player, sia quelli umani che quelli non umani

HumanPlayer: classe che eredita le caratteristiche della classe Player, e in più ha funzioni specifiche per la gestione del Player da parte di un giocatore umano (in particolare la compravendita di terreni e la costruzione di case/alberghi tramite interazoine con l'utente via riga di comando)

ComputerPlayer: classe che eredita le caratteristiche di Player, e gestisce le dimaniche di gioco per un giocatore non umano, e che quindi compie deteminate operazioni in autonomia a seconda di specifici criteri (in particolare compra terreni e costruisce case/alberghi con probabilità del 25%)

Cell: classse che contiene le informazioni che ogni casella della tavola deve avere; in particolare gestisce il tipo di casella, la presenza o meno di costruzioni e la presenza di giocatori in essa tramite delle opportune variabili booleane

Board: gestisce il tabellone, rappresentato tramite un array di oggetti Cell; essa gestisce il movimento di giocatori tra le celle e la stampa del tabellone (è stata aggiunta la funzione che permette di vedere se una cella è acquistata attraverso un numero in apice a sinistra rispetto alla lettera che indica il tipo di cella)

I file del sorgente sono divisi nelle sottodirectory: 
-src: file che contengono le definizioni dei metodi di ogni classe e il sorgente del main
-include: header delle classi che contengono le funzioni e le variabili relative a ogni classe

C'è inoltre una cartella Logs che contiene i log di due partite svolte in 25 turni per ogni giocatore, una tra un umano e tre computer (HumanLog.txt) e una tra quattro computer (ComputerLog.txt); essa conterrà (ogni volta che viene eseguito il programma) anche un file Log.txt, che contiene il log dell'ultima partita giocata.

Schema dell'inclusione delle classi:

 ------      -------      --------      ------
| Cell | -> | Board | -> | Player | -> | Game |
 ------      -------      --------      ------
                            /   \  (queste sono classi figlie)
              -------------      ----------------
             | HumanPlayer |    | ComputerPlayer |
              -------------      ----------------

L'intero progetto è compilabile tramite CMake all'interno di una oppurtuna directory build (da creare) e l'eseguibile si troverà nella stessa directory con il nome di main.

Il progetto è stato diviso in questo modo (gli autori dei vari file sono comunque riportati in testa a ogni file):
-Manuel Andretto ha sviluppato la classe Player e le relative classi figlie
-Lorenzo Nardin ha sviluppato le classi Cell e Board
-Marco Spolverato ha sviluppato la classe Game e il file che contiene il main

Note:

Marco Spolverato 2032569: Ho avuto, nella funzione player_order(), delle difficoltà a gestire le situazioni con 3 o più giocatori in pareggio. in quanto non sono riuscito a
                          gestire al meglio la situazione in cui avvengono nuovi pareggi nel risolvere quelli precedenti.
                          Ad esempio, se 3 giocatori ottengono 4, poi 2 di essi ottengono 9 e uno 5, e nel risolvere il pareggio uno dei 2 ottiene 5, avverrà lo spareggio
                          tra esso e il giocatore che aveva ottenuto 5.
                          Pareggi con valori diversi (due giocatori ottengono 5 e due giocatori ottengono 7) invecec, vengono risolti separatamente e mantenendo l'ordine.