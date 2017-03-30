<?php

session_start ();
include("vues/v_entete.php");
include("vues/v_navbar.php");
include("include/class.pdophp.inc.php");
include("include/ftc.inc.php");

if(!isset($_REQUEST['choix'])){
    $_REQUEST['choix']='accueil';
}
$choix = $_REQUEST['choix'];
switch($choix){
	case 'accueil':{
		include("vues/v_accueil.php");break;
	}
        case 'ajoutBDD':{
		include("vues/v_ajoutBDD.php");break;
            break;
	}
	case 'renametable':{
		include("vues/v_renametable.php");break;
	}
	case 'supptable':{
		include("vues/v_supptable.php");break;
	}
	case 'elemtable':{
		include("vues/v_elemtable.php");break;
	}
	case 'edittable':{
		include("vues/v_edittable.php");break;
	}
	case 'stattable':{
		include("vues/v_stattable.php");break;
	}
	case 'ajouttable':{
		include("vues/v_ajouttable.php");break;
	}
        case 'editname':{
		include("vues/v_editname.php");break;
	}
        case 'c_affgestbdd':{
		include("controler/c_affgestbdd.php");break;
	}
         case 'choix_bdd':{
		include("vues/v_choix_bdd.php");break;
	}
        case 'choix_btable':{
            include("vues/v_choix_btable.php");break;
        }
        case 'c_gest_table':{
            include("controler/c_gest_table.php");break;
        }
         case 'choix_btableligne':{
            include("vues/v_choix_btableligne.php");break;
        }
         case 'c_gest_ligne':{
            include("controler/c_gest_ligne.php");break;
        }
        case 'c_affi':{
            include("controler/c_affi.php");break;
        }
         case 'libre':{
            include("vues/v_sql_libre.php");break;
        }
        //c_gest_ligne
}
include("vues/v_pied.php") ;
?>

