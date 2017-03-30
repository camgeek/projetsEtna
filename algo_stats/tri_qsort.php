<?php
	function tri_qsort($tab)
	{
		global $count;
		$count = 0;
		$start = microtime(true);
		$tab = tri_rapide($tab);
		$end = microtime(true) - $start;
		$rep = [$end, $count];
		$repi = [$rep, $tab];
		return($repi);
	}

	function tri_rapide($tab)
	{
		global $count;
		$size = count($tab);
		$moitie1 = array();
		$moitie2 = array();
		$i = 1;
		if($size <= 1)
		{
			return $tab;
		}
		else
		{
			$pivot = $tab[0];
			while($i < $size)
			{
				$count++;			
				if($tab[$i] < $pivot){
					$moitie1[] = $tab[$i];
				}
				else{
					$moitie2[] = $tab[$i];
				}
				$i++;
			}
			$tab = array_merge(tri_rapide($moitie1), array($pivot), tri_rapide($moitie2));
			return $tab;
		}
	}