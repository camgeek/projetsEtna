<?php
$action = $_REQUEST['action'];
switch ($action){
  case 'addtable':{
    
   if (isset($_REQUEST['bdd']))
     $_SESSION['bdd'] = $_REQUEST['bdd'];
   if (isset($_REQUEST['nom']))
   {
     $name = $_REQUEST['nom'];
     create_table($name, $_SESSION['bdd']);
     include("vues/v_accueil.php");
   }
   else
   {
     include("vues/v_ajouttable.php");
   }
   break;
 }
 
 case 'gestion':{
  
   if (isset($_REQUEST['bdd']))
   {
     $_SESSION['bdd'] = $_REQUEST['bdd'];
     include("vues/v_tables.php");
   }
   break;
 }
 
 case 'renametable':{
  
   if (isset($_REQUEST['nom']))
   {
     $name = $_REQUEST['nom'];
     rename_table($_SESSION['bdd'], $_SESSION['rtable'], $name);
     include("vues/v_accueil.php");
   }
   
   if (isset($_REQUEST['rtable']))
   {
     $_SESSION['rtable'] = $_REQUEST['rtable'];
     include("vues/v_renametable.php");
   }
   else if(!isset ($_REQUEST['nom']))
     include("vues/v_tables.php");
   break;
 }

 case 'addstruct':{
  
   if (isset($_REQUEST['nom']))
   {
     $name = $_REQUEST['nom'];
     $type = $_REQUEST['type'];
     $taille = $_REQUEST['taille'];
     $attribut = $_REQUEST['attribut'];
     if (isset($_REQUEST['ai']))
       $ai = $_REQUEST['ai'];
     else
       $ai = "";
     
     if (isset($_REQUEST['null']))
       $null = $_REQUEST['null'];
     else
       $null = "NOT NULL";
     $index = $_REQUEST['index'];
     
     $reponse = traitement_struct($name, $ai, $index, $attribut, $type, $taille);
     
     add_elem_table($_SESSION['bdd'], $_SESSION['rtable'], $reponse[0], $type, $reponse[4], $reponse[3], $null, $reponse[1], $reponse[2]);
     include("vues/v_accueil.php");
   }
   
   if (isset($_REQUEST['rtable']))
   {
     $_SESSION['rtable'] = $_REQUEST['rtable'];
     include("vues/v_elemtable.php");
   }
   else if(!isset ($_REQUEST['nom']))
     include("vues/v_tables.php");
   break;
 }
 
 case 'delstruct':{
  
   if (isset($_REQUEST['nom']))
   {
     $name = $_REQUEST['nom'];
     del_elem_table($_SESSION['bdd'], $_SESSION['rtable'], $name);
     include("vues/v_accueil.php");
   }
   
   if (isset($_REQUEST['rtable']))
   {
     $_SESSION['rtable'] = $_REQUEST['rtable'];
     $struct = aff_struct_table($_SESSION['bdd'], $_SESSION['rtable']);
     include("vues/v_supptable.php");
   }
   else if(!isset ($_REQUEST['nom']))
     include("vues/v_tables.php");
   break;
 }
 
 case 'Modifstruct':{
  
  if (isset($_REQUEST['newname']))
  {
    $newname = $_REQUEST['newname'];
    $type = $_REQUEST['type'];
    $taille = $_REQUEST['taille'];
    $attribut = $_REQUEST['attribut'];
    if (isset($_REQUEST['ai']))
     $ai = $_REQUEST['ai'];
   else
     $ai = "";
   
   if (isset($_REQUEST['null']))
    $null = $_REQUEST['null'];
  else
    $null = "NOT NULL";
  $index = "";
  
  $reponse = traitement_struct($newname, $ai, $index, $attribut, $type, $taille);
  
  modif_elem_table($_SESSION['bdd'], $_SESSION['rtable'], $reponse[0], $type, $reponse[4], $reponse[3], $null, $reponse[1], $reponse[2],$_SESSION['name']);
  include("vues/v_accueil.php");
  
}

if (isset($_REQUEST['nom']))
{
 $_SESSION['name'] = $_REQUEST['nom'];
 include("vues/v_editstruct.php");
}

if (isset($_REQUEST['rtable']))
{
 $_SESSION['rtable'] = $_REQUEST['rtable'];
 $struct = aff_struct_table($_SESSION['bdd'], $_SESSION['rtable']);
 include("vues/v_edittable.php");
}
else if(!isset ($_REQUEST['nom']) && !isset ($_REQUEST['newname']))
 include("vues/v_tables.php");
break;
}
}