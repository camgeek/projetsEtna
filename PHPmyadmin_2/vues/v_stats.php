  <div class="container">
    
    <p>Nom des tables :</p> 
    <?php
    $i = 0;
    foreach ($infos as $value) {
      echo ($value[0]." créée le ".$value[11]." mémoire : ".$memoires[$i][0]." Mo <br>");
      $i++;
    }
    ?>
    <br><p>nombre de tables : </p><?php echo $i; ?>