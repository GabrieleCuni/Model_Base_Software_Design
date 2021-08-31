Michele:
Ragazzi per chi ha fatto Gtest con gli input da Simulink test e non riesce ad aumentare la coverage:
In pratica simulink test non aggiorna l'effetto degli input nella maniera corretta ogni volta che ne inserite di nuovi o diversi. Fa diventare le varie branches verdi in base a ciò che cambiate ma non vi fa vedere quelle in cui non passate con i nuovi input. Quello che bisogna fare è chiudere e salvare l'harness e rientrare ogni volta che si aggiungono dei nuovi input per vedere il vero effetto della coverage
