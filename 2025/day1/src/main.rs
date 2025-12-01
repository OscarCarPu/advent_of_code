use std::fs::File;
use std::io::{self, BufReader, BufRead};
use std::process;

fn main() -> io::Result<()> {
    let mut cnt: i64 = 0;
    let mut initial: i64 = 50;

    let filename = "input.txt";

    let file = match File::open(filename) {
        Ok(f) => f,
        Err(e) => {
            eprintln!("Error opening file {}: {}", filename, e);
            process::exit(1);
        }
    };

    let reader = BufReader::new(file);

    for line_result in reader.lines() {
        let line = match line_result {
            Ok(l) => l,
            Err(e) => {
                eprintln!("Error reading line: {}. Skipping.", e);
                continue;
            }
        };

        let direction = line.chars().next().unwrap();
        let value_str = &line[1..];

        let value: i64 = match value_str.parse() {
            Ok(v) => v,
            Err(e) => {
                eprintln!("Warning: Could not parse value from line '{}'. Error: {}. Skipping.", line, e);
                continue;
            }
        };

        if direction == 'L' {
            initial = (initial - value % 100 + 100) % 100;
        } else {
            initial = (initial + value) % 100;
        }

        if initial == 0 {
            cnt += 1;
        }
    }

    println!("{}", cnt);

    Ok(())
}
