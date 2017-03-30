<?php

/**
 * remplace par " - " tous les caracters speciaux d'une chaine
 * @author Vrignaud camille <camille.vrignaud1@gmail.com> 
 * @param type $chaine
 * @return type retourne la chaine sans les carctére sépciaux
 */
function cleanCaracteresSpeciaux ($chaine)
{
	setlocale(LC_ALL, 'fr_FR');

	$chaine = iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', $chaine);

	$chaine = preg_replace('#[^0-9a-z]+#i', ' ', $chaine);

	while(strpos($chaine, '--') !== false)
	{
		$chaine = str_replace('--', '-', $chaine);
	}

	$chaine = trim($chaine, '-');

	return $chaine;
}

function traitement_struct($name, $ai, $index, $attribut, $type, $taille)
{
  $name = cleanCaracteresSpeciaux($name);
  if ($ai != "")
    $ai = "AUTO_INCREMENT";
  
  if ($index == "PRIMARY")
    $index = ", ADD PRIMARY KEY (`".$name."`)";
  else if($index == "UNIQUE")
    $index = ", ADD UNIQUE (`".$name."`)";
  else if($index == "INDEX")
    $index = ", ADD INDEX (`".$name."`)";
  else if($index == "FULLTEXT")
    $index = ", ADD FULLTEXT (`".$name."`)";
  else if($index == "SPATIAL")
    $index = ", ADD SPATIAL (`".$name."`)";
  else
    $index = "";
  
  if ($attribut == "__")
    $attribut = "";
  
  if ($type == "DATE")
    $taille = "";
  else
    $taille = "(".$taille.")";
  
  $reponse = array($name, $index, $ai, $attribut, $taille);
  
  return $reponse;
}

function traitement_reponse($reponse)
{
  $val = "(";
  foreach ($reponse as $value)
  {
    $val = $val."'".$value."', ";
  }
  $val = substr($val, 0, (strlen($val)-2));
  $val = $val.")";
  return $val;
}

function traitement_name_col($colum)
{
  $col = "(";
  foreach ($colum as $value) {
    $col = $col.$value[0].", ";
  }
  
  $col = substr($col, 0, (strlen($col)-2));
  $col = $col.")";
  return $col;
}

function traitement_values($values, $names)
{
  $val = "";
  $keys = array_keys($names[0]);
  $keys = array_merge($keys);
  $taille = sizeof($keys);
  for ($i = 0; $i < $taille ; $i++)
  {
    if (is_numeric($keys[$i]))
    {
      unset($keys[$i]);
    }
  }
  $keys = array_merge($keys);
  $values = array_merge($values);
  for ($i = 0; $i < sizeof($values); $i++)
  {
    if (!is_numeric($values[$i]))
      $values[$i] = "'".$values[$i]."'";
    $val = $val.$keys[$i]." = ".$values[$i].", ";
  }
  $val = substr($val, 0, (strlen($val)-2));
  return $val;
}

function traitement_modif_name ($name, $value)
{
 return $val = $name." = ".$value;
}

?>