   <div class="container">
     <?php
     
     $lesbases = show_database();
     foreach ($lesbases as $value) {
       ?><input type="button" value="Supprimer" onclick="javascript:location.href='index.php?choix=c_affgestbdd&action=del&name=<?php echo $value[0] ?>'">
       <input type="button" value="Modifier" onclick="javascript:location.href='index.php?choix=c_affgestbdd&action=del'">
       <input type="button" value="Stats" onclick="javascript:location.href='index.php?choix=c_affgestbdd&action=stat&name=<?php echo $value[0] ?>'">
       <?php
       echo ($value[0]."<br>");
     }
     ?>


