<?php

function tri_peigne($tab) {
    $time_start = microtime(true);
    $cout = 0;
    $permut = true;
    $size = count($tab);
    $real_size = count($tab);
    while (($permut = TRUE) && ($size != 1))
    {
        $permut = FALSE;
        $size = ($size / 1.3);
        $size = floor($size);
        if ($size < 1)
            $size = 1;
        for ($i = 0; $i < ($real_size - $size); $i++)
        {
            if ($tab[$i] > $tab[($i + $size)])
            {
                $permut = TRUE;
                $temp = $tab[$i];
                $tab[$i] = $tab[($i + $size)];
                $tab[($i + $size)] = $temp;
            }
            $cout++;
        }
        $cout++;
    }
    $time_end = microtime(true);
    $time = $time_end - $time_start;
    $rep = [$time, $cout];
    $repi = [$rep, $tab];
    return $repi;
}
