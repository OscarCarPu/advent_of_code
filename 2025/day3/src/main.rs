use std::fs::File;
use std::io::{self, BufRead, BufReader};
use std::process;

fn main() -> io::Result<()> {
    let filename = "input.txt";

    let file = match File::open(filename) {
        Ok(f) => f,
        Err(_) => process::exit(1),
    };

    let reader = BufReader::new(file);

    let mut sol = 0;

    for lines in reader.lines() {
        let line = match lines {
            Ok(l) => l,
            Err(_) => continue,
        };

        let mut first_digit = 0;
        let mut max = 0;

        for c in line.chars() {
            let digit = c.to_digit(10).unwrap();
            max = max.max(first_digit * 10 + digit);
            if digit > first_digit {
                first_digit = digit;
            }
        }

        println!("{}", max);
        sol += max;
    }

    println!("Answer: {}", sol);

    Ok(())
}
