
function validateData1(){
	console.log("validating");
	var gm = document.getElementById("gmail");
	var pw = document.getElementById("pass");
	if(((gm != null) && (pw != null)) && (gm.value !== "" && pw.value !=="")){	//if variables exist
		var user_gm = gm.value;
		var user_pw = pw.value;
		auth = firebase.auth();
		const promise = auth.signInWithEmailAndPassword(user_gm, user_pw);	//sign in user
		promise.then(user => {
		},
				rejectionReason => {
					alert(rejectionReason)	//notify user of any error
				});
		return false;
	}
	alert("Please input both a username and password");	//if either gm or pw were empty, notify user and have them try again
	return true;
}
//Sign in to google and ask for calendar access
function validateData() {
	if (!firebase.auth().currentUser) {
		// [START createprovider]
		var provider = new firebase.auth.GoogleAuthProvider();
		// [END createprovider]
		// [START addscopes]
		provider.addScope('https://www.googleapis.com/auth/calendar');
		// [END addscopes]
		// [START signin]
		var signedInUser = firebase.auth().signInWithPopup(provider);
		signedInUser.then(function(result) {
			// This gives you a Google Access Token. You can use it to access the Google API.
			var token = result.credential.accessToken;
			// The signed-in user info.
			var user = result.user;

			// [START_EXCLUDE]

			// [END_EXCLUDE]
		}).catch(function(error) {
			// Handle Errors here.
			var errorCode = error.code;
			// [START_EXCLUDE]

			if (errorCode === 'auth/popup-closed-by-user') {
				console.log(error);
			} else {
				alert(error);
			}
			// [END_EXCLUDE]
		});
		// [END signin]
	}
}
