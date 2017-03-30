<?php
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', '' );
define( 'DB_HOST', 'localhost' );

function add_bdd($nameBDD)
{
    $pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
    $requete = "CREATE DATABASE IF NOT EXISTS `".$nameBDD."` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci";
    $pdo->prepare($requete)->execute();
}

function show_database()
{
    $pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
    $requete = "SHOW DATABASES";
    $req = $pdo->query($requete);
    $lesLignes = array();          
    $lesLignes =  $req->fetchAll();  
    return $lesLignes; 
}

function del_database($name)
{
  $pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
  $requete = "DROP DATABASE ".$name;
  $pdo->prepare($requete)->execute();
}

function stat_database($name)
{
    $pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
    $requete = "SHOW TABLE STATUS FROM ".$name;
    $req = $pdo->query($requete);
    $lesLignes = array();         
    $lesLignes =  $req->fetchAll();
    return $lesLignes; 
}

function memoire_table($name)
{
    $pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
    $requete = "SELECT round(((data_length + index_length) / 1024 / 1024), 2)
    FROM information_schema.tables 
    WHERE table_schema = '".$name."'";
    $req = $pdo->query($requete);
    $lesLignes = array();    
    $lesLignes =  $req->fetchAll();
    return $lesLignes;
}

function create_table($name, $bdd)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "CREATE TABLE `".$bdd."`.`".$name."` ( `empty` VARCHAR(1) NOT NULL ) ENGINE = InnoDB";
    $pdo->prepare($requete)->execute();
}

function show_tables($bdd)
{
  $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
  
  $requete = "show tables";
  $req = $pdo->query($requete);
  $lesLignes = array();
  $lesLignes =  $req->fetchAll();
  return $lesLignes;
}

function rename_table($bdd, $rtable, $name)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "RENAME TABLE ".$rtable." TO ".$name;
    $pdo->prepare($requete)->execute();
}

function add_elem_table($bdd, $table, $name, $type, $taille, $attribut, $null, $ai, $index)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "ALTER TABLE ".$table." ADD ".$name." ".$type." ".$taille." ".$attribut." ".$null." ".$ai." ".$index;
    $pdo->prepare($requete)->execute();
}

function del_elem_table($bdd, $table, $name)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "ALTER TABLE ".$table." DROP ".$name;
    $pdo->prepare($requete)->execute();
}

function aff_struct_table($bdd, $table)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    $requete = "SHOW COLUMNS FROM ".$table;
    $req = $pdo->query($requete);
    $lesLignes = array();
    $lesLignes =  $req->fetchAll();
    return $lesLignes;
}

function modif_elem_table($bdd, $table, $newname, $type, $taille, $attribut, $null, $ai, $index, $name)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "ALTER TABLE ".$table." CHANGE ".$name." ".$newname." ".$type." ".$taille." ".$attribut." ".$null." ".$ai." ".$index;
    $pdo->prepare($requete)->execute();
}

function add_ligne($bdd,$table,$names,$values)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "INSERT INTO ".$table." ".$names." VALUES ".$values ; 
    $pdo->prepare($requete)->execute(); 
}

function aff_all_table($bdd,$table)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    $requete = "SELECT * FROM ".$table;
    $req = $pdo->query($requete);
    $lesLignes = array();
    $lesLignes =  $req->fetchAll();
    return $lesLignes; 
}

function del_ligne($bdd,$table,$info,$name)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "DELETE FROM ".$table." WHERE ".$name." =".$info;
    $pdo->prepare($requete)->execute(); 
}


function aff_ligne($bdd,$table,$name,$value)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    $requete = "SELECT * FROM ".$table." WHERE ".$name." = ".$value;
    $req = $pdo->query($requete);
    $lesLignes = array();
    $lesLignes =  $req->fetchAll();
    return $lesLignes; 
}

function modif_ligne($bdd,$table,$info,$values)
{
    $pdo = new PDO("mysql:host=".DB_HOST.";dbname=".$bdd, DB_USER, DB_PASSWORD);
    
    $requete = "UPDATE ".$table." SET ".$values." WHERE ".$info;
    $pdo->prepare($requete)->execute();
}

function requete_sql($requete)
{
   
        $pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
        $req = $pdo->query($requete);
        if($req != NULL)
        {
            $lesLignes = array();
            $lesLignes =  $req->fetchAll(); 
            return $lesLignes;
        }
        else
            return NULL;
     
}
