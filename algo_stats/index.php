<?php
session_start();
if (!isset($_SESSION["chart"]))
    $_SESSION["chart"] = "";
if (!isset($_SESSION["chart2"]))
    $_SESSION["chart2"] = "";
?>

<!DOCTYPE html>
<HTML>
    <head>
        <title>Algorithme de Tri</title>
        <meta charset="UTF-8"/>
        <link href="https://fonts.googleapis.com/css?family=Open+Sans+Condensed:300" rel="stylesheet">
        <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.css">
        <link rel="stylesheet" type="text/css" href="style.css" />
    </head>
    <body>
        <div id="body_algo">
            <h1>Algorithme de Tri</h1>
            <form method="post" action="tri.php">
                <div class="form-group col-md-6 col-sm-12">
                <label for="nb_case">Selectionner le nombre de case du tableau :</label>
                <SELECT name="nb_case" size="1" class="form-control">
                    <OPTION>10</OPTION>
                    <OPTION>100</OPTION>
                    <OPTION>1000</OPTION>
                    <OPTION>10000</OPTION>
                </SELECT> 
                </div>
                <div class="form-group col-md-6 col-sm-12">
                <label for="nb_iteration">Selectionner le nombre d'itération du tri:</label>
                <input type="number" class="form-control" name="nb_iteration" value="1" min="1" max="5"/>
                </div>
                <div class="form-group col-md-12 col-sm-12">
                <input type="submit" class="btn btn-primary" name="gen_trie" value="Tableau déjà trié"/>
                <input type="submit" class="btn btn-primary" name="gen_inverse" value="Tableau trié inverse"/>
                <input type="submit" class="btn btn-primary" name="gen_rand" value="Tableau random"/>
                <input type="submit" class="btn btn-primary" name="gen_quasi_trie" value="Tableau quasiment trié"/>
                <input type="submit" class="btn btn-primary" name="gen_doublons" value="Tableau avec beaucoup de doublons"/>
                <input type="submit" class="btn btn-primary" name="gen_all" value="Comparer pour toutes les séries"/>
                </div>
            </form>
            <div class="row">
                <div id="resultat_couts" class="col-md-6 col-sm-12">
                    <h2>Comparatif des Coûts</h2>
                    <canvas id="myChart"></canvas>
                </div>
                <div id="resultat_time" class="col-md-6 col-sm-12">
                    <h2>Comparatif du temps</h2>
                    <canvas id="myChart2"></canvas>
                </div>
            </div>
        </div>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.1.4/Chart.min.js"></script>
        <script>
<?php
echo $_SESSION["chart"];
?>
        </script>
        <script>
<?php
echo $_SESSION["chart2"];
?>
        </script>
    </body>
</HTML>
