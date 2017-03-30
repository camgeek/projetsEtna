   <div class="container">

    <h1>
      Liste des tables : 
    </h1>
    
    <?php
    
    $lestables = show_tables($_SESSION['bdd']);
    foreach ($lestables as $value) {
     ?><input type="button" value="Ajouter une ligne" onclick="javascript:location.href='index.php?choix=c_gest_ligne&action=addligne&rtable=<?php echo $value[0] ?>'">
     <input type="button" value="Supprimer une ligne" onclick="javascript:location.href='index.php?choix=c_gest_ligne&action=delligne&rtable=<?php echo $value[0] ?>'">
     <input type="button" value="Modifier une ligne" onclick="javascript:location.href='index.php?choix=c_gest_ligne&action=modifligne&rtable=<?php echo $value[0] ?>'">
     <?php
     echo ($value[0]."<br>");
   }