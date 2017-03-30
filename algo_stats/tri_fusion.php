<?php
	function tri_fusion(&$tab)
	{
		global $count;
		$count = 0;
		$start = microtime(true);
		tri_fusion_exec($tab);
		$end = microtime(true) - $start;
		$rep = [$end, $count];
		$repi = [$rep, $tab];
		return($repi);
	}

	function tri_fusion_exec(&$tab)
	{
		global $count;
		$size = count($tab);
		$i = 0;
		if($size != 1)
		{
			$moitie1 = array();
			$moitie2 = array();
			while($i < $size)
			{
				$count++;
				if($i < ($size / 2))
					$moitie1[] = $tab[$i];
				else
					$moitie2[] = $tab[$i];
				$i++;
			}
			tri_fusion_exec($moitie1);
			tri_fusion_exec($moitie2);
			fusion($moitie1, $moitie2, $tab);
		}
	}

	function fusion($moitie1, $moitie2, &$tab) {
		global $count;
		$i = 0;
		$j = 0;
		$k = 0;
		$size_m1 = count($moitie1);
		$size_m2 = count($moitie2);
		while($j < $size_m1 && $k < $size_m2)
		{
			$count++;
			if($moitie1[ $j ] < $moitie2[ $k ])
				$tab[ $i ] = $moitie1[ $j++ ];
			else
				$tab[ $i ] = $moitie2[ $k++ ];
			$i++;
		}
		while($j < $size_m1)
		{
			$count++;
			$tab[ $i ] = $moitie1[ $j++ ];
			$i++;
		}
		while($k < $size_m2)
		{
			$count++;
			$tab[ $i ] = $moitie2[ $k++ ];
			$i++;
		}
	}