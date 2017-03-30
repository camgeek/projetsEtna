<?php
// images.php for c in /home/camille/imagepanel
// 
// Made by VRIGNAUD camille
// Login   <vrigna_c@etna-alternance.net>
// 
// Started on  Fri Nov  4 22:38:36 2016 VRIGNAUD camille
// Last update Sat Nov  5 09:23:26 2016 VRIGNAUD camille
//

function	dl_content($liens)
{
  $content_all = "";
  $regex = '/<img.*src="([^>"]*)/';
  $i = 0;

  while(isset($liens[$i]))
    {
      $content = file_get_contents($liens[$i]);
      $content_all .= $content;
      $i = $i + 1;
    }
  preg_match_all($regex, $content_all, $tab);
  return($tab[1]);
}