   <div class="container">

    <h1>
      Liste des tables : 
    </h1>
    
    <?php
    
    $lestables = show_tables($_SESSION['bdd']);
    foreach ($lestables as $value) {
     ?><input type="button" value="Renommer" onclick="javascript:location.href='index.php?choix=c_gest_table&action=renametable&rtable=<?php echo $value[0] ?>'">
     <input type="button" value="Ajouter structure" onclick="javascript:location.href='index.php?choix=c_gest_table&action=addstruct&rtable=<?php echo $value[0] ?>'">
     <input type="button" value="Supprimer structure" onclick="javascript:location.href='index.php?choix=c_gest_table&action=delstruct&rtable=<?php echo $value[0] ?>'">
     <input type="button" value="Modifier" onclick="javascript:location.href='index.php?choix=c_gest_table&action=Modifstruct&rtable=<?php echo $value[0] ?>'">
     <input type="button" value="Afficher" onclick="javascript:location.href='index.php?choix=c_affi&action=aff&rtable=<?php echo $value[0] ?>'">
     <?php
     echo ($value[0]."<br>");
   }
