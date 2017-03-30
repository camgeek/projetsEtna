<?php
$action = $_REQUEST['action'];
switch ($action){
  
 case 'gestion':{
   
   if (isset($_REQUEST['name']))
   {
    $_SESSION['bdd'] = $_REQUEST['name'];
    include("vues/v_tables.php");
  }
  break;
}

case 'aff':{
 
 if (isset($_REQUEST['rtable']))
 {
  $_SESSION['rtable'] = $_REQUEST['rtable'];
  $values = aff_all_table($_SESSION['bdd'],$_SESSION['rtable']);
  include("vues/v_aff_tables.php");
}
break;
}

case 'libre':{
 
 if (isset($_REQUEST['req']))
 {
   $reponse = requete_sql($_REQUEST['req']);
   if (is_array($reponse))
   {
     include("vues/v_aff_sql.php");
   }
   else
   {
     echo "erreur";
     include("vues/v_acceuil.php");
   }
     
 }
 
 break;
}
}
