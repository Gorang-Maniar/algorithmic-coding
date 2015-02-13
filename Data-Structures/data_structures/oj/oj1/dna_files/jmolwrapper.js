

function showJmol(fileLocation, scriptLocation) {

	showJmol(fileLocation, scriptLocation, 500);
}

function showJmol(fileLocation, scriptLocation, size) {

	showJmol(fileLocation, scriptLocation, size, molName);
}


function showJmol(fileLocation, scriptLocation, size, molName) {
	
	
			
		if (size == undefined) { size = 500; }
		if (molName == undefined) { molName = "momJmol" }
		
		
		if ( jmolPath_global == undefined) {
			jmolPath_global = "/pdb/Viewers/jmol-12.0.18";
		}
		
		jmolInitialize(jmolPath_global,true);
	
		var server = location.protocol+ "//" + location.hostname + ":" +  location.port ;
	
		
		var fileLoc   = server + fileLocation;
		var scriptLoc = server + scriptLocation;
	
		jmolApplet(size, "load " + fileLoc + " ; script " + scriptLoc +";" ,molName); 
	
		jmolBr();
		
		pageTracker._trackEvent('Viewers', 'Jmol/MOM', scriptLocation,0);
	
}