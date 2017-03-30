   <div class="container">


   	<?php
   	
   	$lesbases = show_database();
   	foreach ($lesbases as $value) {
   		?>
   		<input type="button" value="Gestion" onclick="javascript:location.href='index.php?choix=c_gest_ligne&action=gestion&bdd=<?php echo $value[0] ?>'">
   		<?php
   		echo ($value[0]."<br>");
   	}

