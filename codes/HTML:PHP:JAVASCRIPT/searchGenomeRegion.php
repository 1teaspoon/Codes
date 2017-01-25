<?php
		$userName = filter_input(INPUT_GET, "name");
		$stage = filter_input(INPUT_GET, "stage");
	    $servername = "localhost:8889";
		$username = "root";
		$password = "root";
		$dbname = "EP";

	// Create connection
	$db = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($db->connect_error) {
    	die("Connection failed: " . $db->connect_error);
	}
	$sql = "SELECT * FROM $stage";
	if(!$result = $db->query($sql)){
    	die('There was an error running the query [' . $db->error . ']');
	}
	echo 'enhchr'." ".'enhchrstart'." ".'enhchrend'." ".'tsschr'." ".'tssstart'." ".'tssid'." ".'genename'." ".'fpkm'.'<br />';
	while($row = $result->fetch_assoc()){
    	if ($row['enhchrstart']<$userName[0] && $row['enhchrend']>$userName[0]){
    		
    		echo $row['enhchr']." ".$row['enhchrstart']." ".$row['enhchrend']." ".$row['tsschr']." ".$row['tssstart']." ".$row['tssid']." ".$row['genename']." ".$row['fpkm'].'<br />';
    		
    	}
    	
	}
	$db->close();

		
?>