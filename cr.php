//extract data from the post
extract($_POST);

//set POST variables
$url = 'http://gpo.iitb.ac.in/src/redirect.php';

user

$fields_string="login_username=yadalok&secretkey=06061993"

//open connection
$ch = curl_init();

//set the url, number of POST vars, POST data
curl_setopt($ch,CURLOPT_URL, $url);
curl_setopt($ch,CURLOPT_POST, 2);
curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);

//execute post
$result = curl_exec($ch);

//close connection
curl_close($ch);