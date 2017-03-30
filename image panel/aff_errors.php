<?php
// aff_errors.php for c in /home/camille/imagepanel
// 
// Made by VRIGNAUD camille
// Login   <vrigna_c@etna-alternance.net>
// 
// Started on  Fri Nov  4 18:34:41 2016 VRIGNAUD camille
// Last update Sat Nov  5 09:22:08 2016 VRIGNAUD camille
//

function	aff_errors($res)
{
  static $erreurs = array(
		   '1' => "La base est manquante\n",
		   '2' => "Pas de liens\n",
		   '3' => "Site web indisponible\n"
		   );
  if(isset($erreurs[$res]))
    {
      echo $erreurs[$res];
      echo "Le script fonctionne de la manière suivante :\n
 ./imagepanel.php [options] lien1 [lien2[...]] base\n";
    }
}