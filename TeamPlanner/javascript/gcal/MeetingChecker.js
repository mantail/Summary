//takes a list of date time 2 tuples, and the minimum length of the meeting in minutes.
function MeetingChecker(dtList, duration){
	var bestTimes = new Set();
	var mostPPL = 0;
	var active = new Array();
	var start = 0;

	var rmv = new Array();
	var len = dtList.length;
	for (var i = 0; i<len;i++){
		if ((dtList[i][1]-dtList[i][0]) < duration){
			rmv.push(i);
		}
	}

	var len2 = rmv.length;
	for (var j = len2; j > 0; j--){
		delete dtList[rmv[j]];
	}

	var len3 = dtList.length;
	for (var k = 0; k < len3; k++){
		var templi = dtList.slice(0,k);
		var start = dtList[k];


		var len4 = templi.length;
		for (var x = 0; x < len4; x++){
			if ((templi[x][1] - dtList[k][0]) >= duration){
				active.push(templi[x]);
			}
		}

		if (active.length > mostPPL){
			mostPPL = active.length;
			bestTimes = [];
			bestTimes.push(dtList[k][0]);
		}

		else if (mostPPL == active.length){
			bestTimes.add(dtList[k][0])
		}
		active = [];
	}
	return (bestTimes, mostPPL+1);
}
