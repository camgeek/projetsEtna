<?php
	session_start();
	set_time_limit(0);
	include_once("ftc_create.php");
	include_once("tri_bulle.php");
	include_once("tri_insertion.php");
	include_once("tri_selection.php");
	include_once("tri_fusion.php");
	include_once("tri_peigne.php");
	include_once("tri_qsort.php");
	include_once("tri_shell.php");

	if(isset($_POST["gen_trie"]))
		$tab = create_table_trie($_POST["nb_case"]);
	else if(isset($_POST["gen_inverse"]))
		$tab = create_table_inverse($_POST["nb_case"]);
	else if(isset($_POST["gen_rand"]))
		$tab = create_table_rand($_POST["nb_case"]);
	else if(isset($_POST["gen_quasi_trie"]))
		$tab = create_table_quasi($_POST["nb_case"]);
	else if(isset($_POST["gen_doublons"]))
		$tab = create_table_double($_POST["nb_case"]);
	else if(isset($_POST["gen_all"]))
		$tab = array(create_table_trie($_POST["nb_case"]), create_table_inverse($_POST["nb_case"]), create_table_rand($_POST["nb_case"]), create_table_quasi($_POST["nb_case"]), create_table_double($_POST["nb_case"]));

	$tab_fusion = $tab;

	if(isset($_POST["nb_iteration"]))
		$nb_iteration = $_POST["nb_iteration"];
	$i = 0;
	$stat = array(0, 0, 0, 0, 0, 0, 0);

	while($i != $nb_iteration)
	{
		if(isset($_POST["gen_all"]))
		{
			$bulle = tri_bulle($tab[$i]);
			$insertion = tri_insertion($tab[$i]);
			$selection = tri_selection($tab[$i]);
			$rapide = tri_qsort($tab[$i]);
			$shell = tri_shell($tab[$i]);
			$peigne = tri_peigne($tab[$i]);
			$fusion = tri_fusion($tab[$i]);
		}
		else
		{
			$bulle = tri_bulle($tab);
			$insertion = tri_insertion($tab);
			$selection = tri_selection($tab);
			$rapide = tri_qsort($tab);
			$shell = tri_shell($tab);
			$peigne = tri_peigne($tab);
			$fusion = tri_fusion($tab_fusion);
		}

		$stat[0] += $bulle[0][0];
		$stat[1] += $insertion[0][0];
		$stat[2] += $selection[0][0];
		$stat[3] += $rapide[0][0];
		$stat[4] += $shell[0][0];
		$stat[5] += $peigne[0][0];
		$stat[6] += $fusion[0][0];

		$i++;
	}

	$stat[0] /= $nb_iteration;
	$stat[1] /= $nb_iteration;
	$stat[2] /= $nb_iteration;
	$stat[3] /= $nb_iteration;
	$stat[4] /= $nb_iteration;
	$stat[5] /= $nb_iteration;
	$stat[6] /= $nb_iteration;

	$script = "var ctx = document.getElementById(\"myChart\").getContext('2d');
		var myChart = new Chart(ctx, {
		  type: 'pie',
		  data: {
		    labels: [\"Tri à Bulle\", \"Tri par Insertion\", \"Tri par Selection\", \"Tri Rapide\", \"Tri Shell\", \"Tri Peigne\", \"Tri Fusion\"],
		    datasets: [{
		      backgroundColor: [
		        \"#2ecc71\",
		        \"#3498db\",
		        \"#95a5a6\",
		        \"#EEEEC6\",
		        \"#E70739\",
		        \"#FFB6B8\",
		        \"#FE9C03\"
		      ],
		      data: [";
		      $script .= $bulle[0][1].", ".$insertion[0][1].", ".$selection[0][1].", ".$rapide[0][1].", ".$shell[0][1].", ".$peigne[0][1].", ".$fusion[0][1];
		      $script .= "]
		    }]
		  }
		});";

	$script_time = "var ctx = document.getElementById(\"myChart2\").getContext('2d');
		var myChart = new Chart(ctx, {
		  type: 'bar',
		  data: {
		    labels: [\"Time (en s)\"],
		    datasets: [{
		      backgroundColor: [\"#2ecc71\"],
		      label: 'Tri à Bulle',
		      data: [".$stat[0]."]
		    }, {
		      backgroundColor: [\"#3498db\"],
		      label: 'Tri par Insertion',
		      data: [".$stat[1]."]
		    }, {
		      backgroundColor: [\"#95a5a6\"],
		      label: 'Tri par Selection',
		      data: [".$stat[2]."]
		    }, {
		      backgroundColor: [\"#EEEEC6\"],
		      label: 'Tri Rapide',
		      data: [".$stat[3]."]
		    }, {
		      backgroundColor: [\"#E70739\"],
		      label: 'Tri Shell',
		      data: [".$stat[4]."]
		    }, {
		      backgroundColor: [\"#FFB6B8\"],
		      label: 'Tri Peigne',
		      data: [".$stat[5]."]
		    }, {
		      backgroundColor: [\"#FE9C03\"],
		      label: 'Tri Fusion',
		      data: [".$stat[6]."]
		    }]
		  }
		});";

		$_SESSION["chart"] = $script;
		$_SESSION["chart2"] = $script_time;
		header('Location: index.php');
		exit;

