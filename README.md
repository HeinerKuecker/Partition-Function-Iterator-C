# Partition-Function-Iterator-C
Partition Function or Integer Partition as Iterator in C

Jede Integer Partitionierung wird in jeder moeglichen Reihenfolge erzeugt.

Every integer partitioning is created in every possible order.

Example:

1

    1


2

    1 1
    
    2


3

    1 1 1
    
    1 2
    
    2 1
    
    3


4

    1 1 1 1
    
    1 1 2
    
    1 2 1
    
    1 3
    
    2 1 1
    
    2 2
    
    3 1
    
    4


5

    1 1 1 1 1
    
    1 1 1 2
    
    1 1 2 1
    
    1 1 3
    
    1 2 1 1
    
    1 2 2
    
    1 3 1
    
    1 4
    
    2 1 1 1
    
    2 1 2
    
    2 2 1
    
    2 3
    
    3 1 1
    
    3 2
    
    4 1
    
    5


Der Algorithmus arbeitet folgendermassen:

The algorithm works as follows:

N ist eine natuerliche Zahl, die partitioniert werden soll.

N is a natural number to be partitioned.

X ist eine natuerliche Zahl, die von 1 bis N schrittweise um 1 erh�ht wird.

X is a natural number that is incremented by 1 from 1 to N.

partitions(0) := leere Menge

partitions(0) := empty set

partitions(N) := X konkateniert mit allen partitions(N - X)

partitions(N) := X concatenates with all partitions(N - X)

Der Iterator speichert die aktuelle Partitionierung bis zum naechsten Aufruf.

The iterator saves the current partitioning until the next call.

Die Funktion init dient zum Setzen der zu partitionierenden Zahl.

The init function is used to set the number to be partitioned.

Die Funktion has_next dient zum Pruefen des Vorhandenseins der n�chsten Partitionierung.

The has_next function is used to check the existence of the next partitioning.

Die Funktion next dient zum Zurueckgeben der n�chsten Partitionierung.

The next function is used to return the next partitioning.

Die aktuelle Partitionierung wird als 0-terminiertes Array �bergeben.

The current partitioning is passed as a 0-terminated array.

Du kannst dieses Projekt in Eclipse CDT importieren.

You can import this project into Eclipse CDT.

See also my Repository [Partition-Function-recursive-C](https://github.com/HeinerKuecker/Partition-Function-recursive-C).
