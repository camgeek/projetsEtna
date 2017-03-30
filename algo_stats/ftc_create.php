<?php

/*
 * Crée un tableau déja trié par ordre croissant, le nombre d'éléments créée est passer en paramètre
 * Renvoie un tableau
 */

function create_table_trie($nombre) {
    $tab = array();
    $i = 0;
    while ($i < $nombre) {
        array_push($tab, $i);
        $i++;
    }
    return $tab;
}

/*
 * Crée un tableau trié en orde décroissant, le nombre d'éléments créée est passer en paramètre
 * Renvoie un tableau
 */

function create_table_inverse($nombre) {
    $tab = array();
    while ($nombre > 0) {
        array_push($tab, $nombre);
        $nombre--;
    }
    return $tab;
}

/*
 * Crée un tableau avec des valeurs aléatoire, le nombre d'éléments créée est passer en paramètre
 * Renvoie un tableau
 */

function create_table_rand($nombre) {
    $tab = array();
    $i = 0;
    while ($i < $nombre) {
        array_push($tab, rand());
        $i++;
    }
    return $tab;
}

/*
 * Crée un tableau à 80% triés en orde croissant et ensuite le rempli avec du random pour les 20% restant 
 * le nombre d'éléments créée est passer en paramètre
 * Renvoie un tableau
 */

function create_table_quasi($nombre) {
    $tab = array();
    $i = 0;
    $temp = $nombre * 0.8;
    while ($i <= $temp) {
        array_push($tab, $i);
        $i++;
    }
    while ($i < $nombre) {
        array_push($tab, rand());
        $i++;
    }
    return $tab;
}

/*
 * Crée un tableau à 80% de double ensuite le rempli avec du random pour les 20% restant 
 * le nombre d'éléments créée est passer en paramètre
 * Renvoie un tableau
 */

function create_table_double($nombre) {
    $tab = array();
    $i = 0;
    $temp = $nombre * 0.8;
    while ($i <= $temp) {
        array_push($tab, rand(10, 12));
        $i++;
    }
    while ($i < $nombre) {
        array_push($tab, rand());
        $i++;
    }
    shuffle($tab);
    return $tab;
}
