var jf = require("johnny-five");

const circuito = new jf.Board()

let celda, led, motor

const ondear = () => {
    console.log("Luz:", celda.value)
    if(celda.value > 600) {
        led.off()
        motor.to(180)
    } else if(celda.value > 200) {
        motor.to(90)
        led.off()
    } else {
        motor.to(0)
        led.on()
    }

    setTimeout(ondear, 500)
}

circuito.on("ready", () => {
    led = new jf.Led(13)
    motor = new jf.Servo(9)
    led.on()
    motor.to(0)

    const configuracion = {
        pin: "A0",
        freq: 50
    }

    celda = jf.Sensor(configuracion)
    ondear()
})