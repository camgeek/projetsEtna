<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

$app = new \Slim\App;

if (!isset($_SERVER['PHP_AUTH_USER'])){
header('WWW-Authenticate: Basic realm="My Realm"');
header('HTTP/1.0 401 Unauthorized');
exit;
}

$app->options('/{routes:.+}', function ($request, $response, $args) {
    return $response;
});

$app->add(function ($req, $res, $next) {
    $response = $next($req, $res);
    return $response
            ->withHeader('Access-Control-Allow-Origin', '*')
            ->withHeader('Access-Control-Allow-Headers', 'X-Requested-With, Content-Type:application/json, Accept, Origin, Authorization')
            ->withHeader('Content-Type', 'application/json')
            ->withHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE, OPTIONS');
});


//Route 1 BON
//Ajouter un utilisateur
$app->post('/users', function(Request $request, Response $response){
    login(true);
    $first_name = $request->getParam('firstname');
    $last_name = $request->getParam('lastname');
    $email = $request->getParam('email');
    $password = $request->getParam('password');
    $password = md5($password);
    $role = $request->getParam('role');
    
    $sql = "INSERT INTO user (`id`, `lastname`, `firstname`, `email`, `password`, `role`) VALUES
    (NULL,:last_name,:first_name,:email,:password,:role)";

    try{
        // Get DB Object
        $db = new db();
        // Connect
        $db = $db->connect();

        $stmt = $db->prepare($sql);

        $stmt->bindParam(':first_name', $first_name);
        $stmt->bindParam(':last_name',  $last_name);
        $stmt->bindParam(':email',      $email);
        $stmt->bindParam(':password',   $password);
        $stmt->bindParam(':role',       $role);
        $stmt->execute();

           header('HTTP/1.0 201   Created User');
           $rep['firstName'] = $first_name;
           $rep['lastName'] = $last_name;
           $rep['email'] = $email;
           $rep['password'] = $password;
           $rep['role'] = $role;
           echo json_encode($rep);
           exit;

    } catch(PDOException $e){
        header('HTTP/1.0 400  ErrorResponse');
        header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "400";
           $rep['message'] = $e->getMessage();
           echo json_encode($rep);
           exit;
    }
});

/*
 * Route 2 BON
 * Modifie un utilisateur
 */
$app->put('/user/{id}', function(Request $request, Response $response){
    login(true);
    $first_name = $request->getParam('firstname');
    $last_name = $request->getParam('lastname');
    $email = $request->getParam('email');
    $password = $request->getParam('password');
    $password = md5($password);
    $role = $request->getParam('role');
    $id = $request->getAttribute('id');

    $sql = "UPDATE user SET
				lastname 	= :last_name,
				firstname 	= :first_name,
                email		= :email,
                password 	= :password,
                role 		= :role
			WHERE id = $id";

    try{
        // Get DB Object
        $db = new db();
        // Connect
        $db = $db->connect();

        $stmt = $db->prepare($sql);

        $stmt->bindParam(':first_name', $first_name);
        $stmt->bindParam(':last_name',  $last_name);
        $stmt->bindParam(':email',      $email);
        $stmt->bindParam(':password',   $password);
        $stmt->bindParam(':role',       $role);

        $stmt->execute();
        if ($stmt->rowCount() == 0)
        {
           header('HTTP/1.0 204  No datas');
           echo "No datas";
           exit;
        }
       else {
           
       
        $stmt = $db->query("SELECT * FROM user where id = '".$id."'");
        $rep = $stmt->fetchAll(PDO::FETCH_OBJ);

           echo json_encode($rep);
           exit;
       }
           

    } catch(PDOException $e){
        header('HTTP/1.0 404  Not Found ErrorResponse');
        header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "404";
           $rep['message'] = $e->getMessage();
           echo $rep['message'];
           exit;
    }
});


/*
 *Route 3 BON
 * Supprime un utilisateur 
 */
$app->delete('/user/{id}', function(Request $request, Response $response){
    login(true);
    $id = $request->getAttribute('id');

    $sql = "DELETE FROM user WHERE id = $id";

    try{
        // Get DB Object
        $db = new db();
        // Connect
        $db = $db->connect();

        $stmt = $db->prepare($sql);
        
        $stmt->execute();
        //$array = $stmt->fetchALL();
        //$nb = count($array);
        //echo $nb;
        $db = null;
        if ($stmt->rowCount() == 0)
        {
           echo "No datas";
           header("Content-Type: application/json; charset=UTF-8");
           header('HTTP/1.0 204  No datas');
           exit;
        }
        else
        {
          echo "User successfully deleted";
          header("Content-Type: application/json; charset=UTF-8");
           header('HTTP/1.0 200 User successfully deleted');
           
           exit;
        }
    } catch(PDOException $e){
          header('HTTP/1.0 404  Not Found ErrorResponse');
          header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "404";
           $rep['message'] = $e->getMessage();
           echo json_encode($rep);
           exit;
    }
});

/*
 * Route 4
 * Affiche un user selon sont ID
 */
$app->get('/user/{id}', function(Request $request, Response $response){
    login(false);
    $id = $request->getAttribute('id');

    $sql = "SELECT * FROM user WHERE id = $id";

    try{
        // Get DB Object
        $db = new db();
        // Connect
        $db = $db->connect();

        $stmt = $db->query($sql);
        $user = $stmt->fetch(PDO::FETCH_OBJ);
        $db = null;
        if ($stmt->rowCount() == 0)
        {
           header('HTTP/1.0 404 Not Found ErrorResponse');
           header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "404";
           $rep['message'] = "User was not found";
           echo json_encode($rep);
           exit;
        }
        else
        {
        header("HTTP/1.0 200 User definition Object");
        header("Content-Type: application/json; charset=UTF-8");
        echo json_encode($user);
        exit;
        }
    } catch(PDOException $e){
          header('HTTP/1.0 400  Not Found ErrorResponse');
          header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "400";
           $rep['message'] = $e->getMessage();
           echo json_encode($rep);
           exit;
    }
});

/*
 *  Route 5 BON
 *  Get All Users 
 */
$app->get('/users', function(Request $request, Response $response){
    $sql = "SELECT * FROM user";
 $login = apache_request_headers();
 login(false);
    try{
        // Get DB Object
        $db = new db();
        // Connect
        $db = $db->connect();

        $stmt = $db->query($sql);
        $customers = $stmt->fetchAll(PDO::FETCH_OBJ);
        $db = null;
        header("HTTP/1.0 200 An array of users");
        header("Content-Type: application/json; charset=UTF-8");
        echo json_encode($customers);
        exit;
    } catch(PDOException $e){
          header('HTTP/1.0 400  ErrorResponse');
          header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "400";
           $rep['message'] = $e->getMessage();
           echo json_encode($rep);
           exit;
    }
 
});

/*
 * Route 6 BON
 * Chercher un user avec sont nom ou sont mail
 */
$app->get('/user/search/{q}/{count}', function(Request $request, Response $response){
    login(false);
    $recherche = $request->getAttribute('q');
    $count = $request->getAttribute('count');
    $sql = "SELECT * from user WHERE lastname = '".$recherche."' OR email = '".$recherche."' LIMIT $count";

    try{
        // Get DB Object
        $db = new db();
        // Connect
        $db = $db->connect();

        $stmt = $db->query($sql);
        $user = $stmt->fetch(PDO::FETCH_OBJ);
        $db = null;
        if ($user != false){
        header("HTTP/1.0 200 User definition Object");
        header("Content-Type: application/json; charset=UTF-8");
        $array['data'] = $user;
        echo json_encode($array);
        exit;
        }
        else
        {
           header('HTTP/1.0 404 Not Found ErrorResponse');
           header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "404";
           $rep['message'] = "User was not found";
           echo json_encode($rep);
           exit;
        }
    } catch(PDOException $e){
       header('HTTP/1.0 400  ErrorResponse');
          header("Content-Type: application/json; charset=UTF-8");
           $rep['code'] = "400";
           $rep['message'] = $e->getMessage();
           echo json_encode($rep);
           exit;
    }
});

function login($admin)
{
    if(isset($_SERVER['PHP_AUTH_USER']) && isset($_SERVER['PHP_AUTH_PW']))
    {
         $db = new db();
        // Connect
        $db = $db->connect();
        
       $email = $_SERVER['PHP_AUTH_USER'];
       $mdp = $_SERVER['PHP_AUTH_PW'];
       $mdp = sha1($mdp);
      
       $sql = "SELECT * from user WHERE email = '".$email."' AND password = '".$mdp."'";
       $stmt = $db->query($sql);
       $connect = $stmt->fetchAll();
       $db = null;
       if ($connect == NULL)
       {
          header('HTTP/1.0 401  Must be connected');
          header("Content-Type: application/json; charset=UTF-8");
          echo "You must be connected";
//          $rep['code'] = "401";
//          $rep['message'] = "Must be connected";
//          echo json_encode($rep);
          exit;
       }
       else if($connect[0]['role'] != "admin" && $admin)
       {
           header('HTTP/1.0 403  Must be admin');
           header("Content-Type: application/json; charset=UTF-8");
           echo "You must be admin";
//           $rep['code'] = "403";
//           $rep['message'] = "Must be admin";
//           echo json_encode($rep);
           exit;
       }
    }
}