   <div class="container">

   	<h1>
   		Ajout d'une ligne à la table
   	</h1>
   	
   	<form method='POST' action='index.php?choix=c_gest_ligne&action=addligne'>
            <table class ="table-condensed">
   		<?php
   		foreach ($struct as $value) {
                    echo "<tr>";
                    echo "<td><strong>Colonne :</strong> ".$value[0]."</td> <td><strong>Type : </strong>".$value[1]."</td> <td><strong>Valeur :</strong>
                    <input  type='text' name=".$value[0]." size='12' maxlength='12' required=''></td>";
                    echo "</tr>";
   		}
   		?>
            <input type='hidden' name='check' value='oui'>
            </table>
   		<input type='submit' value='Valider' name='valider'>
   	</form>

