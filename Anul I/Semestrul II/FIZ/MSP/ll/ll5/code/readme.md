# pseudocode

1. la listele fluxurilor se adauga 0
2. se identifica drumurile utilizand parcurgerea in adancime
3. se stablisete fluxul minim



```
initialize flow to 0
path = findAugmentingPath(G, s, t)
while path exists:
    augment flow along path                 #This is purposefully ambiguous for now
    G_f = createResidualGraph()
    path = findAugmentingPath(G_f, s, t)
return flow
```
