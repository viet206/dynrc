package main
import (
	"os/exec"
	"fmt"
	"flag"
	"os"
)

func main() {
	cc := "gcc"
	cflags := "-Werror -Wall -Wextra -shared -fPIC"
	src := "-I../src ../src/core/core.c ../src/hal/hal_libc.c ../src/compat/compat.c -o"
	target := "./libdyn.so"

	build_command := fmt.Sprintf("%s %s %s %s",cc,cflags,src,target)

	flag.Parse()
	args := flag.Args()
	
	if len(args) > 0 {
		subcommand := args[0]
		
		switch subcommand {
			case "build":
				cmd := exec.Command("sh","-c",build_command)

				output, err := cmd.CombinedOutput()
				if err != nil {
				    fmt.Printf("=== BUILD ERROR ===\n%s\n", string(output))
				    os.Exit(1)
				}
			default:
				fmt.Printf("Không hiểu lệnh: %s\n", subcommand)
		}
	} else {
			fmt.Println("Vui lòng truyền lệnh (ví dụ: test hoặc build)")
	}
}
