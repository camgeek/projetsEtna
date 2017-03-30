<?php

function tri_bulle($Tab) {
    $cout = 0;
    $time_start = microtime(true);
    $taille = count($Tab);
    foreach ($Tab as $tableau)
    {
        for ($i = 0; $i < $taille; $i++)
        {
            $cout++;
            if (isset($Tab[$i + 1]) && ($Tab[$i] > $Tab[$i + 1]))
            {
                $j = $Tab[$i + 1];
                $Tab[$i + 1] = $Tab[$i];
                $Tab[$i] = $j;
            }
        }
        $taille = $taille - 1;
        $cout++;
    }
    $time_end = microtime(true);
    $time = $time_end - $time_start;
    $rep = [$time, $cout];
    $repi = [$rep, $Tab];
    return $repi;
}
