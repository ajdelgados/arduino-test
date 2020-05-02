var jf = require("johnny-five");

const circuito = new jf.Board()

circuito.on("ready", () => {
    const led = new jf.Led(13)
    led.blink(2000)
    console.log("Sé hacer hardware")
})