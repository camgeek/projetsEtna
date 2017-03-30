#!/usr/bin/env php
<?php
// imagepanel.php for c in /home/camille/imagepanel
// 
// Made by VRIGNAUD camille
// Login   <vrigna_c@etna-alternance.net>
// 
// Started on  Fri Nov  4 13:57:10 2016 VRIGNAUD camille
// Last update Sat Nov  5 09:45:08 2016 VRIGNAUD camille
//

include("aff_errors.php");
include("argv_control.php");
include("images.php");
include("options.php");

$res = 0;
$cont = 0;
$options = argv_control($argv, $argc, $cont);
$options = array_unique($options);
$str = implode($options);
$options = str_split($str);
aff_options($options);
$liens = html_control($argv, $argc);
$res = err_argv($cont, $liens, $argc);
$res1 = website_test($liens);
if ($res > 0)
  aff_errors($res);
else if($res1 > 0)
  aff_errors($res1);
else
  {
    $liens_images = dl_content($liens);
    echo count($liens_images)." Images trouver \n";
  }