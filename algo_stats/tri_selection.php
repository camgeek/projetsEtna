<?php

function tri_selection($tab) {
    $time_start = microtime(true);
    $taille = count($tab);
    $cout = 0;
    while ($taille > 0)
    {
        $tmp = $tab[0];
        $n = 0;
        for ($i = 0; $i < $taille; $i++)
        {
            $cout++;
            if ($tmp < $tab[$i])
            {
                $tmp = $tab[$i];
                $n = $i;
            }
        }
        $tip = $tab[$taille - 1];
        $tab[$taille - 1] = $tab[$n];
        $tab[$n] = $tip;
        $taille--;
        $cout++;
    }
    $time_end = microtime(true);
    $time = $time_end - $time_start;
    $rep = [$time, $cout];
    $repi = [$rep, $tab];
    return $repi;
}
