<?php
// options.php for c in /home/camille/imagepanel
// 
// Made by VRIGNAUD camille
// Login   <vrigna_c@etna-alternance.net>
// 
// Started on  Sat Nov  5 09:01:25 2016 VRIGNAUD camille
// Last update Sat Nov  5 09:17:24 2016 VRIGNAUD camille
//

function	aff_options($options)
{
  $i = 0;
  while(isset($options[$i]) && $options[$i] != NULL)
    {
      echo "Vous avez activez l'option : ".$options[$i]." mais elle n'est pas
encore implémenter \n";
      $i = $i + 1;
    }
}