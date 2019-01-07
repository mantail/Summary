var workingStartTime = 2018-05-12T08:00:00.000Z;
var workingEndTime = 2018-05-12T22:00:00.000Z;

function GetAllCalendarId() {
  var request = gapi.client.calendar.calendarList.list();

  request.execute(function(resp){
      var calendars = resp.items;
      console.log(calendars);
      for(i = 0; i < calendars.length; i++){
        var calendar = calendars[i];
        console.log("Calendar ID(Primary?):\t"+calendar.id+"("+calendar.primary+")\n");
        console.log("Calendar Summary:\t"+calendar.summary+"\n\n");
        ListEvents(calendar.id);
      }
    });
  }
  function ListEvents(calId) {
   var request =  gapi.client.calendar.events.list({
      'calendarId': calId,
      'timeMin': (new Date(2018, 11, 28)).toISOString(),
      'timeMax': (new Date(2018, 12, 8)).toISOString(),
      'showDeleted': false,
      'singleEvents': true,
      //'maxResults': 50

      'orderBy': 'startTime'
    });
    request.execute(function(response){
      console.log("Calendar ID RECIEVED BY FUNC:\t"+calId + "\n");

      var events = response.items;
      console.log("Event list length " + events.length + "\n");
      if(events.length > 0) {
        for(i = 0; i < events.length; i++) {
          var event = events[i];
          var start = event.start.dateTime;
          var end = event.end.dateTime;
          // if(!start || !end) {
          //    start = event.start.date;
          //    end = event.end.date;
          // }
          console.log("Events\n" + event.summary);
          console.log("start: "+start);
          console.log("\tend: "+ end);
        }
      }
    });
  }
