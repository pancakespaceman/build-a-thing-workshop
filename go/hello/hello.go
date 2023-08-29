package main
import (
    "fmt"
    "log"

    "example.com/greetings"
)

// import "rsc.io/quote"

 func main() {
    // fmt.Println(quote.Go())

    // Set properties of th epredefined Logger, including
    // the log entry prefix and a glag to disable printing
    // the time, source file, and line number
    log.SetPrefix("greetings: ")
    log.SetFlags(0)

    // Request a greeting message
    message, err := greetings.Hello("Shawn")

    // If an error was returned, print it to the console and exit the program
    if err != nil {
        log.Fatal(err)
    }

    // If no error was returned, print the returned message to the console
    fmt.Println(message)

    // A slice of names.
    names := []string{"Shawn", "Jim", "Tyler", "Heidi", "John"}

    // Request greeting messages for the names.
    messages, err := greetings.Hellos(names)

    if err != nil {
        log.Fatal(err)
    }

    // If no error was returned, print the returned map of messages to the console
    fmt.Println(messages)
 }
