<?php

function tri_insertion($tab)
{
	$start = microtime(true);
	$size = count($tab);
	$i = 1;
	$j = 0;
	$cout = 0;
	while($i < $size)
	{
		$temp = $tab[$i];
		$j = $i;
		while($j > 0 && $tab[$j - 1] > $temp)
		{
			$tab[$j] = $tab[$j - 1];
			$cout++;
			$j--;
		}
		$tab[$j] = $temp;
		$i++;
		$cout++;
	}
	$end = microtime(true) - $start;
	$rep = [$end, $cout];
	$repi = [$rep, $tab];
	return($repi);
}
