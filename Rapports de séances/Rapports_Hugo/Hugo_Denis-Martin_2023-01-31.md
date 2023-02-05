# Rapport de séance du mardi 31/01/2023

### Goal of the session: Finalize the scaning process

Après un court-cicruit qui a détruit une carte de commande de moteur, je me suis vu obligé de recabler l'ensemble de l'alimentation en puissance du robot afin de sécuriser ce dernier pour l'avenir. 

Je me suis également rendu compte que les vis à l'intérieur de la boîte de protection de la carte arduino étaient à l'orignie de court-circuit. En les sécurisant avec du scotch isolant ce qui à réglé beaucoup de bug que j'avais dans mon programme.

<br />

J'ai ensuite fini le code du scan afin qu'il stock les mesure qu'il prend dans un tableau qui sera ensuite analysé pour prendre une décision et éviter les obstacles

![](Annexes/2023-02-05_Code.jpg)

<br />

Le code dans le main a été revu afin qu'il soit plus propre et plus optimisé

