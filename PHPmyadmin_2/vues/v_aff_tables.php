  <div class="container">


    <?php
    
         $i = 0;
         echo "<table class='table table-striped'> <tr>";
         foreach ($values as $value) {
          foreach ($value as $key1 => $val) {
            if (!is_numeric($key1) && $i < 1)
            {
             echo "<th>".$key1."</th>";
           }
         }
         $i++;
       }
       echo "</tr>";
       foreach ($values as $value) {
         echo "<tr>";
         foreach ($value as $key1 => $val) {
          if (!is_numeric($key1))
          {
           echo "<td>".$val."</td>";
         }
       }
       echo "</tr>";
     }
     echo "</table>";
     ?>