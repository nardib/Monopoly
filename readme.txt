Progetto finale per l'insegnamento "Laboratorio di Programmazione" per l'A.A. 2023/24
Collaboratori: Manuel Andretto, Lorenzo Nardin, Marco Spolverato

Descrizione del progetto:

main: crea un oggetto della classe Game, che gestisce tutte le dinamiche del gioco, e fa partire il gioco tramite un'opportuno metodo start_game()

Game: classe che gestisce le dimaniche di gioco, in particolare fa in modo che le regole vengano rispettate e contiene opportune funzioni per la gestione del gioco

Player: classe base che contiene le caratteristiche comuni a tutti i player, sia quelli umani che quelli non umani

HumanPlayer: classe che eredita le caratteristiche della classe Player, e in più ha funzioni specifiche per la gestione del Player da parte di un giocatore umano

ComputerPlayer: classe che eredita le caratteristiche di Player, e gestisce le dimaniche di gioco per un giocatore non umano, e che quindi compie deteminate operazioni in autonomia a seconda di specifici criteri

Cell: classse che contiene le informazioni che ogni casella della tavola deve avere; in particolare gestisce il tipo di casella, la presenza o meno di costruzioni e la presenza di giocatori in essa tramite delle opportune variabili booleane

Board: gestisce il tabellone, rappresentato tramite un array di oggetti Cell; essa gestisce il movimento di giocatori tra le celle e la stampa del tabellone