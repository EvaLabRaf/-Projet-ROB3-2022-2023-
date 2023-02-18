# Rapport de séance du mardi 14/02/2023

### Goal of the session: Artificial intelligence applied to obstacle avoidance

<br />

Après avoir fini de recabler et organiser correctement le robot, je me suis intéresser de nouveau à la manière d'éviter les obstacles. 

<br />

Pour ce faire j'ai chercher sur internet différentes façon de procéder, j'ai fini par choisir une façon simple qui se base sur 3 mesures du laser (une de face et une pour chaque côté à +/- 60° de la position de face). Ce qui sous-entend que mon axe qui déplace le laser ne bougera plus que sur l'axe horizontal.

<br />

![](Annexes/2023-02-14_TableauSch%C3%A9ma.jpg)

<br />

Ensuite en fonction des différentes distances captées par les lasers le robot fera un choix de direction et allumera soit les moteurs gauches, soit les droits.

<br />

![](Annexes/2023-02-14_TableauV%C3%A9rit%C3%A9.jpg)

<br />

Les distances indiquées sur ce tableau ne sont pas celles que je prendrais mais le fonctionnement sera la même. 

<br />

Dès que j'aurais réussi à programmer ceci et qu'il fonctionnera correctement, je passerais à une version avec plus de valeurs de laser pour d'autres angles.