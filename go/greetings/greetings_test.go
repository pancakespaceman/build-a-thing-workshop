package greetings

import (
    "testing"
    "regexp"
)

// TestHelloName calls greetings.Hello with a name, checking for a valid return value.
func TestHelloName(t *testing.T) {
    name := "Glados"
    want := regexp.MustCompile(`\b`+name+`\b`)
    msg, err := Hello("Glados")

    if !want.MatchString(msg) || err != nil {
        t.Fatalf(`Hello("Glados") = %q, %v, want match for %#q, nil`, msg, err, want)
    }
}


// TestHelloEmpty calls grettings.Hello with an empty string,
// check for an error
func TestHelloEmpty(t *testing.T) {
    msg, err := Hello("")
    if msg != "" || err == nil {
        t.Fatalf(`Hello("") = %q, %v, want "", error`, msg, err)
    }
}
