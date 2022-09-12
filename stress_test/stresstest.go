package main

import "fmt"

func main() {
	var x float32
	for x = 0.0; x < 0.0000000000000000010; x += 0.0000000000000000001 {
		fmt.Println("Random text")
	}
}
