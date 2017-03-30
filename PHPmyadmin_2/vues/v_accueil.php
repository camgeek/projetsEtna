<!-- Page Content -->
<div class="container">

  <div class="row">           
    <div class="col-md-4">
        <center><h1>php my admin</h1></center>
      <p> Page d'accueil </p>               
    </div>
    
  </div>
  <?php
  
  $lesbases = show_database();
  foreach ($lesbases as $value) {
   ?><input type="button" class="btn btn-default acc" value="Afficher" onclick="javascript:location.href='index.php?choix=c_affi&action=gestion&name=<?php echo $value[0] ?>'">
   <?php
   echo $value[0]."<br>";
 }
 ?>