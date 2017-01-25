<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<meta name="keywords" content="" />
<meta name="description" content="" />
<style type="text/css">
	table { table-layout: fixed; }
	.expBorder,.expBorder1
	{
		border:1px solid black;
	}
	.expBorder
	{
		text-align:center;
		width:80px;
	}
	.warn
	{
		background:#CC9933;
	}
	.title{
		font-weight:bold;
		text-align:center;
	}
	.gene{
		font-weight:bold;
	}
	
</style>
<?php include 'download.php';?>
<?php
//	
	$Gene = trim($_POST["search_term"]);
	//print_r($Gene);
	$List = explode(PHP_EOL,$Gene);
	//print_r($List);
	$Gene = str_replace(PHP_EOL, ';', $Gene);
	//print_r($Gene);
	$count = count($List);
	//print_r($count);
	//$con =  mysql_connect("localhost", "root", "Tree1234@");
	$con = new mysqli("localhost:8889", "root", "root", "EP");
	echo "<title>Gene Expression Heat Map -- $Gene</title>";
	
?>
<script src="http://hsc.hms.harvard.edu/javascript/jquery-1.5.1.min.js" type="text/javascript"></script>

</head>
<body>

<div>
<?php
	echo"<h2 class='title'>Gene Expression Heat Map--$Gene</h2>";
?>
<script type="text/javascript">
	function validateForms(){
	var x = document.forms["search_form"]["search_term"].value;
	if (x == null || x == "") {
		alert("No gene input!\n\nPlease input genes for the search.");
		document.getElementById('search_term').focus();
		return false
	}
}
</script>

<div class = 'search'>
<form action="result.php" onsubmit="return validateForms()" method="post" id="search_form">
<b>Search genes:</b>(seperate genes with return and max number of genes is 5)<br> 
<textarea name="search_term" id="search_term" style="width: 200px; height: 100px;"></textarea>
<input type="submit" name="Search" value="Search" />
</form>
</div>

<?php
	if ($count > 5){
		echo "<h1 class = 'warn'>Max Number of Genes Could be listed is 5</h1>";
	}
	else{
		foreach ($List as $name){
			echo "<h4 class = 'gene'>$name:</h4>\n";
			echo "<table>\n";
			echo "<tr>\n";
			$query1 = "Select * from BM where genename = '$name'";
			$result1 = mysql_db_query("genename",$query1,$con);
			$True = mysql_num_rows($result1);
			if ($True != 0){
				$row1 = mysql_fetch_row($result1);
				$low = $row1[1];
				$high = $row1[2];
				echo "<td colspan='12'>Low($low)</td>";
				echo "<td colspan='1'>&nbsp;</td>";
				echo "<td colspan='12' style='text-align: right'>High($high)</td>";
			}
			else{
				echo "<td colspan='12'>Low</td>";
				echo "<td colspan='1'>&nbsp;</td>";
				echo "<td colspan='12' style='text-align: right'>High</td>";
			}
			
			echo "</tr>\n";

			echo "<tr>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#2020ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#3030ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#4040ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#5050ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#6060ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#8080ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#9090ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#a0a0ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#c0c0ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#d0d0ff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ffffff'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ffd0d0'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ffb0b0'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ffa0a0'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff9090'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff8080'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff5050'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff4040'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff3030'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff2020'>&nbsp;</td>\n";
			echo "<td width='25' class='expBorder1' bgcolor='#ff0000'>&nbsp;</td>\n";
			echo "</tr></table>\n";
			
			if ($True != 0){
				echo "<div><a href='download.php?file=.\\export\\" . $name . ".txt'>Export All Expression Values</a> | <a href='mytest.php?gene=". $name ."'>".$name."</a></div>";
				$query = "Select * from gene_id_map where genename = '$name'";
				$result = mysql_db_query("Gene",$query,$con);
				$row = mysql_fetch_row($result);
				echo "<b>Link to the $name Page:</b><a href='http://www.ncbi.nlm.nih.gov/gene/$row[2]' target='new'>NCBI</a> | <a href='http://www.informatics.jax.org/marker/$row[1]' target='new'>MGI</a>";
			}
			
			echo "<div class='main'>\n";

			
			if ($True != 0){
				$query2 = "Select * from data_color where Gene = '$name'";
				$result2 = mysql_db_query("Gene",$query2,$con);
					//echo mysql_num_fields($result2);
				$num = mysql_num_fields($result2);
				echo "<table class = 'one'>";
				echo "<tr>";
				for ($i = 1; $i < $num ; $i++)
				{
					$title = mysql_field_name($result2,$i);
					echo "<td colspan='1' class='expBorder'>$title</td>\n";
				}
				mysql_data_seek($result2,0);
				$row2 = mysql_fetch_row($result2);
				echo "<tr>";
				for ($i = 1; $i < $num ; $i++)
				{
					$title = mysql_field_name($result2,$i);
					echo "<td class='expBorder' bgcolor='$row2[$i]'><div title='$title'>&nbsp;</div></td>\n";
				}
				echo "</tr>";
				echo "</tr>";
				echo "</table>";
					
				mysql_free_result($result2);
				mysql_free_result($result);
				}
			else{
				echo "<h1 class = 'warn'>Gene $List[$i] Not In Database</h1>";
			}
			mysql_free_result($result1);	
			echo "</div>\n";
		}
	}
	mysql_close($con);
?>
</div>

</body>
</html>