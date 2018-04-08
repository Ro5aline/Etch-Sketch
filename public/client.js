var COLOUR =  '#ef97ae';  // pink
var radius = 5;           // Constant radio for the line
var socket = io();        // websocket to the server
var previousPosition=[0,0]; // previous position
var ctx = Sketch.create(); //Creating the drawing context
var firstMessage=true;    // first value

    ctx.container = document.getElementById( 'container' ); //reference drawing canvas
    ctx.autoclear= false; // making sure it stays
    ctx.retina='auto';
    ctx.setup = function() 
    { 
      console.log( 'setup' );
    } // Setup all variables
    ctx.keydown= function() 
    {
    if ( ctx.keys.C ) ctx.clear();
    } // handeling keydowns
// on a 'reset' message clean and reste firstMessage
    socket.on('reset', function() 
    { 
      firstMessage=true;
      ctx.clear();
    });
// handling new sensor values
    socket.on('new-pos', function(cord) { 
//Map the incoming 10-bit numbers
      console.log(cord);
      var x = 1000 -(cord[0] - 250) * 1000 / 150.0
      var y = (cord[1] - 250)*1000/250.0;
      var r = Math.max((1000 - cord[2]) / 6.0, radius);
      var p = [x, y];

      if(firstMessage){ // if its the first message store that value as previous
        firstMessage=false;
        previousPosition=p;
      }
      else
      { // any other message we use to draw.
        ctx.lineCap = 'round';
        ctx.lineJoin = 'round';
        ctx.fillStyle = ctx.strokeStyle = COLOUR;
        ctx.lineWidth = r;
        ctx.beginPath();  //begin a adrawing
        ctx.moveTo( previousPosition[0], previousPosition[1] ); // from
        ctx.lineTo( newPosition[0],  newPosition[1]); // to
        ctx.stroke(); // and only draw a stroke
        previousPosition=p; // update to the new position.
       }
    });
