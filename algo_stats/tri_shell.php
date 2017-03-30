<?php

function tri_shell($tab) {
    $time_start = microtime(true);
    $cout = 0;
    $real_size = count($tab);
    $size = (count($tab) / 2);
    $size = round($size);
    while ($size > 0)
    {
        for ($i = $size; $i < $real_size; $i++)
        {
            $temp = $tab[$i];
            $j = $i;
            while ($j >= $size && $tab[$j - $size] > $temp)
            {
                $tab[$j] = $tab[$j - $size];
                $j -= $size;
                $cout++;
            }
            $tab[$j] = $temp;
            $cout++;
        }
        $size = round($size / 2.2);
        $cout++;
    }
    $time_end = microtime(true);
    $time = $time_end - $time_start;
    $rep = [$time, $cout];
    $repi = [$rep, $tab];
    return $repi;
}
