   <div class="container">

    <h1>
      Form ligne : 
    </h1>
    <form method='POST' action='index.php?choix=c_gest_ligne&action=modifligne'>
      <?php
      foreach ($res as $value) {
        foreach ($value as $key1 => $val) {
          if (!is_numeric($key1))
          {
           echo "Colonne <strong>".$key1."</strong>  Valeur :
           <input  type='text' name=".$key1." size='12' maxlength='12' required='' value=".$val."><br>";
         }
       }
       ?><input type='submit' value='Valider' name='valider'>
       <?php
     }
     ?>
     <input type='hidden' name='check' value='oui'>  
   </form>
