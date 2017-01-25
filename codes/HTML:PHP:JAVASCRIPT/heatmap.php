
<?
$input = isset($_POST['txtarea'])?$_POST['txtarea']:"";
if (strlen($input)==0) {
  echo 'no input';
  exit;
}
$ids = explode("\n", str_replace("\r", "", $input));
?>

<script type="text/javascript">
var ar = <?php echo json_encode($ids) ?>;
</script>

<?php
		$userName = $ids;
	    $servername = "localhost:8889";
		$username = "root";
		$password = "root";
		$dbname = "GENEEXP";
	$db = new mysqli($servername, $username, $password, $dbname);
	if ($db->connect_error) {
    	die("Connection failed: " . $db->connect_error);
	}
	for ($i = 0; $i <3 ; $i++){
	$sql = "SELECT * FROM $stage WHERE genename='$userName[$i]'";
	if(!$result = $db->query($sql)){
    	die('There was an error running the query [' . $db->error . ']');
	}
	while($row = $result->fetch_assoc()){
    	$exp[$i]=$row['exp'];
    	
	}
	}
	$db->close();

		
?>

<head>
  <!-- Plotly.js -->
  <script src="https://cdn.plot.ly/plotly-latest.min.js"></script>
</head>

<body>
  
  <div id="myDiv"><!-- Plotly chart will be drawn inside this DIV --></div>
  <script>
    <!-- JAVASCRIPT CODE GOES HERE -->
    var data = [
  		{
    		z: [$exp[0], $exp[1], $exp[2],
    		x: ['Endo','HE','PreHSC','FL','BM'],
    	    y: [ar[0], ar[1], ar[2]],
    		type: 'heatmap'
  		}
	];

	Plotly.plot('myDiv', data);
  </script>
</body>