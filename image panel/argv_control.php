<?php
// argv_control.php for c in /home/camille/imagepanel
// 
// Made by VRIGNAUD camille
// Login   <vrigna_c@etna-alternance.net>
// 
// Started on  Fri Nov  4 13:47:12 2016 VRIGNAUD camille
// Last update Sat Nov  5 09:24:11 2016 VRIGNAUD camille
//

function	argv_control($argv, $argc, &$cont)
{
  $control = array('g','j','l','n','N','p','s');
  $i = 0;
  global $options;
  $options = array();

  while ($argc > $i)
    {
      if ($argv[$i][0] == "-")
	{
	  $j = 0;
	  $cont = $cont + 1;
	  argv_sup($control, $argv, $i, $j);
	}
      $i = $i + 1;
    }
return($options);
}

function	argv_sup(&$control, $argv, &$i, &$j)
{
  global $options;

  while (isset($control[$j]))
    {
      $m = 0;
      while (isset($argv[$i][$m]))
	{
	  if ($control[$j] == $argv[$i][$m])
	    {
	      $options[] = $argv[$i][$m];
	    }
	  $m = $m + 1;
	}
       $j = $j + 1;
    }
}

function	html_control($argv, $argc)
{
  $i = 0;
  $regex = "/(http|https):\/\/.*\.*/";
  $regex2 ="/.*\.html/";
  $liens = array();

  while ($argc > $i)
    {
      if(preg_match($regex, $argv[$i]) == 1 ||
	 preg_match($regex2, $argv[$i]) == 1)
	$liens[] = $argv[$i];
      $i = $i + 1;
    }
  return ($liens);
}

function	err_argv($count, $tab, $argc)
{
  $tab_nb = count($tab);
  $temp = $tab_nb + $count;
  $temp = $temp + 2;
  $temp = $argc - $temp;

  if ($tab_nb == 0)
    $res = 2;
  else if ($temp != 0)
    $res = 1;
  else
    $res = 0;
  return ($res);
}

function	website_test($liens)
{
  $res = 0;
  $i = 0;

  while (isset($liens[$i]))
    {
      $test = @fopen($liens[$i], 'r');
      if($test)
	{
	  fclose($test);
	  $res = $res + 1;
	}
      $i = $i + 1;
    }
  if (count($liens) == $res)
    $res = 0;
  else
    $res = 3;
  return ($res);
}