   <div class="container">

   	<?php
   	
   	$lesbases = show_database();
   	foreach ($lesbases as $value) {
   		?><input type="button" value="Ajouter une table" onclick="javascript:location.href='index.php?choix=c_gest_table&action=addtable&bdd=<?php echo $value[0] ?>'">
   		<input type="button" value="Gestion" onclick="javascript:location.href='index.php?choix=c_gest_table&action=gestion&bdd=<?php echo $value[0] ?>'">
   		<?php
   		echo ($value[0]."<br>");
   	}
