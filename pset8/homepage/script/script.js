
//Headline typewriter effect
var i = 0;
var txt = "Hi, I'm Rizvan"; /* The text */
var speed = 50; /* The speed/duration of the effect in milliseconds */

window.addEventListener("load", function typeWriter() {
  if (i < txt.length) {
    document.getElementById("typed").innerHTML += txt.charAt(i);
    i++;
    setTimeout(typeWriter, speed);
  }
});