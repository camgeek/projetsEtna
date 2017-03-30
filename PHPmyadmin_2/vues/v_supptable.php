   <div class="container">

   	<h1>
   		Suppression element structure table
   	</h1>
   	
   	<?php
   	foreach ($struct as $value) {
   		?><input type="button" value="Supprimer" onclick="javascript:location.href='index.php?choix=c_gest_table&action=delstruct&nom=<?php echo $value[0] ?>'">
   		<?php
   		echo ($value[0]."<br>");
   	}
   	?>