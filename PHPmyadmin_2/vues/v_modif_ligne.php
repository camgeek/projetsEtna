   <div class="container">

    <h1>
      Modifier une ligne : 
    </h1>
    <?php
    $key = "";
    foreach ($values as $value) {
      foreach ($value as $key1 => $val) {
        if (!is_numeric($key1))
        {
         echo "Colone ".$key1."  Valeur :".$val."  ||";
         if ($key == "")
           $key = $key1;
       }
     }
     ?> <input type="button" value="Modifier" onclick="javascript:location.href='index.php?choix=c_gest_ligne&action=modifligne&info=<?php echo $value[0]?>&name=<?php echo $key?>'"><br>
     <?php
     $key = "";
   }
   ?>
   
