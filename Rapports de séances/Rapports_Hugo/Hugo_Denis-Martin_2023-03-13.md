# Rapport de séance du mardi 13/03/2023

### Goal of the session: Artificial intelligence applied to obstacle avoidance 

<br />

Durant cette séance, j'ai continué le nouveau code du robot. L'idée derrière ce changement est de scanner en continu, voici ce que j'ai fait:

![](Annexes/2023-03-18_CodeSetup.jpg)

![](Annexes/2023-03-18_CodeLoop1.jpg)

![](Annexes/2023-03-18_CodeLoop2.jpg)

<br />

Tant que le temps de BACK_DURATION n'est pas dépassé, le robot ne relance pas un scan, dès que ce temps est dépassé on relance on mesure la distance et si elle est inférieur à 5cm on recule. 

<br />

J'ai rajouté un programme dans la library CapteurDistance, qui prend une valeur de distance pour un angle qui change a chaque passage de la loop. 

![](Annexes/2023-03-18_CodeScan.jpg)

J'ai également rajouté ces deux programme qui permettent de récupérer des valeurs de variables sur la library et les envoyer dans le main.

![](Annexes/2023-03-18_CodeAngle.jpg)

<br />

Pour l'instant le code ne marche pas, la variable qu'on incrémente pour connaître la position du laser ne retourne pas à 0 lorsqu'elle dépasse la valeur maximale. Le laser reste donc coincé après le premier balayage.