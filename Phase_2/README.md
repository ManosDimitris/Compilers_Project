Loipon arxidaki. Tha se mathw ti kai pws gt SAGAPAW.

To hash douleuei etsi pws to kanate xthes kamia allagi.
To mono pou alaksame einai i lista me ta scopes kai to display.

To ScopeList exei mesa ena vector pou periexei oles tis metablites pou brhkame se auto to scope.

To insert pleon douleuei etsi:
-) Trexei to hash function kai bazei to neo SymbolEntry mesa sto Hash table.
-) analoga to scope (tin parametro) kanei mia for gia na brei se poio node tis listas na to balei.
-) Mesa sto loop tsekarei episis an to epomeno node einai null gt an einai i prwti fora pou mpainoume toso bathia mesa sta scopes to node den tha exei
dimiourghtei.
-) Ama brei pws to node einai null dimiourgei ena kainourgio kai to bazei stin lista.
-) Ama den ftasei mexri ekei apla tha paei mexri to node scope (tin parametro) kai tha kanei push_back to stoixeio sto vector ekeinou tou node.




eksigisi me eikones:

Parser briskei to x (des text.txt)
 
to insert tsekarei to ScopeList kai blepei oti einai null:

scopes = NULL

Dhmiourgei kainourio node kai pusharei to SymbolEntry(x, {sometype}, scope:0, line:1) sto vector.

-//////////-

Parser briskei to z (des text.txt)

to insert tsekarei to ScopeList kai blepei oti den einai null:

scopes = ScopeList (gia scope 0) -> NULL
        | vector : [x] |

Paei mexri to node 0 kai pusharei to SymbolEntry(z, {sometype}, scope:0, line:2) sto vector.

scopes = ScopeList (gia scope 0) -> NULL
        | vector : [x], [z] |

-/////////-

Parser auksanei to scope (brike brackets) kai briskei to z (des text.txt)

to insert tsekarei to ScopeList kai blepei oti den einai null:

Paei mexri to node 1 kai blepei oti oppp einai null ara dhmiourgei kainourio node.

scopes = ScopeList (gia scope 0) -> ScopeList (gia scope 1) -> NULL
        | vector : [x], [z] |       | vector:       |

Pusharei to SymbolEntry(m, {sometype}, scope:0, line:2) sto vector

scopes = ScopeList (gia scope 0) -> ScopeList (gia scope 1) -> NULL
        | vector : [x], [z] |       | vector : [m]     |

-/////////-

Parser briskei to o (des text.txt)

to insert tsekarei to ScopeList kai blepei oti den einai null:

To epomeno den einai episis null ara pusharei.

scopes = ScopeList (gia scope 0) -> ScopeList (gia scope 1) -> NULL
        | vector : [x], [z] |       | vector : [m], [o]   |




Dhladh i diadikasia dixnei etsi:

scopes = NULL
--
scopes = ScopeList (gia scope 0) -> NULL
        | vector : [x] |
--
scopes = ScopeList (gia scope 0) -> NULL
        | vector : [x], [z] |
--
scopes = ScopeList (gia scope 0) -> ScopeList (gia scope 1) -> NULL
        | vector : [x], [z] |       | vector:       |
--
scopes = ScopeList (gia scope 0) -> ScopeList (gia scope 1) -> NULL
        | vector : [x], [z] |       | vector : [m]     |
--
scopes = ScopeList (gia scope 0) -> ScopeList (gia scope 1) -> NULL
        | vector : [x], [z] |       | vector : [m], [o]   |
--