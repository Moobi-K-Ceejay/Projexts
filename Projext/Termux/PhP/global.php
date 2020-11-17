<?php
	$NAME = 'Mike';

	function getName()
	{
		global $NAME;
		echo $NAME;
	}
	getName();
	
?>