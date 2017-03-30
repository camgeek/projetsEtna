<?php
$action = $_REQUEST['action'];
switch ($action){
  case 'ajout':{
    
   $name = $_REQUEST['nom'];
   add_bdd($name);
   include("vues/v_accueil.php");
   break;
 }
 
 case 'del':{
  
   $name = $_REQUEST['name'];
   ?>
   <script>alert("êtes vous sur de vouloir supprimer cette base de données ?")</script>
   <?php 
   del_database($name);
   include("vues/v_accueil.php");
   break;
 }
 
 case 'stat':{
  
   $name = $_REQUEST['name'];
   $infos = stat_database($name);
   $memoires = memoire_table($name);
   include("vues/v_stats.php");
   break;
 }
}