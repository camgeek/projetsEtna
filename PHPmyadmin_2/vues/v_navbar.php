<body>

    <!-- Navigation -->
    <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
            </div>
            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav">
                    <li>
                        <a href="index.php?choix=accueil">Accueil</a>
                    </li>
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false"> Affichage et gestions des bases de données<span class="caret"></span></a>
                        <ul class="dropdown-menu">
                            <li><a href="index.php?choix=ajoutBDD">Ajout/création d'une base de données</a></li>
                            <li><a href='index.php?choix=choix_bdd'>Gestion Base de données</a></li>
                            <li><a href="index.php?choix=libre">Requête SQL</a></li>
                        </ul>
                    </li>
                    
                    
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false"> Affichage et gestions des tables d'une base de données<span class="caret"></span></a>
                        <ul class="dropdown-menu">
                            <li><a href='index.php?choix=choix_btable'>Gestion des tables</a></li>
                        </ul>
                    </li>

                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">Affichage et gestion du contenu d'une table<span class="caret"></span></a>
                        <ul class="dropdown-menu">
                            <li><a href="index.php?choix=choix_btableligne">Gestion des occurences</a></li>
                        </ul>
                    </li>
                    
                </div>
                <!-- /.navbar-collapse -->
            </div>
            <!-- /.container -->
        </nav>
        <div class="tous">
        