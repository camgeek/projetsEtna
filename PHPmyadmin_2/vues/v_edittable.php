   <div class="container">

   	<h1>
   		Edition element structure de la table
   	</h1>
   	<?php
   	foreach ($struct as $value) {
   		?><input type="button" value="Modifier" onclick="javascript:location.href='index.php?choix=c_gest_table&action=Modifstruct&nom=<?php echo $value[0] ?>'">
   		<?php
   		echo ($value[0]."<br>");
   	}
   	?>