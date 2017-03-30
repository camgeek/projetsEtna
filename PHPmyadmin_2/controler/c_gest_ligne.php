<?php
$action = $_REQUEST['action'];
switch ($action){

 case 'gestion':{

   if (isset($_REQUEST['bdd']))
   {
    $_SESSION['bdd'] = $_REQUEST['bdd'];
    include("vues/v_table_ligne.php");
}
break;
}

case 'addligne':{

  if(isset($_REQUEST['check']))  
 {
   $envoie = array();
   $i = 0;
   foreach ($_SESSION['struct'] as $value)
   {
       $envoie[$i] = $_REQUEST[$value[0]];
       $i++;
   }
   $values = traitement_reponse($envoie);
   $names = traitement_name_col($_SESSION['struct']);
   add_ligne($_SESSION['bdd'],$_SESSION['rtable'],$names,$values);
   include("vues/v_accueil.php");
}


if (isset($_REQUEST['rtable']))
{
   $_SESSION['rtable'] = $_REQUEST['rtable'];
   $struct = aff_struct_table($_SESSION['bdd'], $_SESSION['rtable']);
   $_SESSION['struct'] = $struct;
   include("vues/v_add_ligne.php");
}
else if(!isset($_REQUEST[$_SESSION['struct'][0][0]]))
   include("vues/v_table_ligne.php");
break;
}

case 'delligne':{
   if (isset($_REQUEST['info']))
   {
    $info = $_REQUEST['info'];
    $name = $_REQUEST['name'];
    if (!is_numeric($info))
        $info = "'".$info."'";
    del_ligne($_SESSION['bdd'],$_SESSION['rtable'],$info,$name);
    include("vues/v_accueil.php");
}


if (isset($_REQUEST['rtable']))
{
   $_SESSION['rtable'] = $_REQUEST['rtable'];
   $values = aff_all_table($_SESSION['bdd'],$_SESSION['rtable']);
   include("vues/v_del_ligne.php");
}
else if(!isset($_REQUEST['info']))
   include("vues/v_table_ligne.php");
break;
}

case 'modifligne':{

   if (isset($_REQUEST['check']))
   {
       $envoie = array();
       $i = 0;
       $lala = "";
       foreach ($_SESSION['res'] as $value) {
           foreach ($value as $key1 => $val)
           {
              if (!is_numeric($key1))
              {
                 if ($lala == "")
                     $lala = $key1;
                 $envoie[$i] = $_REQUEST[$key1];
                 $i++;
             }
             $i++;
         }
     }
     $name = traitement_modif_name ($lala, $_SESSION['info']);
     $values = traitement_values($envoie, $_SESSION['res']);
     modif_ligne($_SESSION['bdd'],$_SESSION['rtable'],$name,$values);
 }

 if (isset($_REQUEST['info']))
 {
    $info = $_REQUEST['info'];
    $name = $_REQUEST['name'];
    if (!is_numeric($info))
        $info = "'".$info."'";
    $_SESSION['info'] = $info;
    $res = aff_ligne($_SESSION['bdd'],$_SESSION['rtable'],$name,$info);
    $_SESSION['res'] = $res;
    include ("vues/v_form_modif_ligne.php");
}

if (isset($_REQUEST['rtable']))
{
   $_SESSION['rtable'] = $_REQUEST['rtable'];
   $values = aff_all_table($_SESSION['bdd'],$_SESSION['rtable']);
   include("vues/v_modif_ligne.php");
}
else if(!isset($_REQUEST['info']))
   include("vues/v_table_ligne.php");
break;
}
}
