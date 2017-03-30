  <div class="container">
  	
  	<h1>
  		Renommer la table : <?php echo $_SESSION['rtable'] ?>
  	</h1>
  	
  	<form method='POST' action='index.php?choix=c_gest_table&action=renametable'>
  		<p>Taper le nouveau nom de la table</p>  
  		<input  type='text' name=nom  size='12' maxlength='12'>
  		<input type='submit' value='Valider' name='valider'>
  	</form>