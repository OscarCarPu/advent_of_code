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

        let mut v: Vec<i64> = line
            .chars()
            .take(12)
            .map(|c| c.to_digit(10).unwrap() as i64)
            .collect();

        let mut pos = 11;
        for i in 0..v.len() - 1 {
            if v[i] < v[i + 1] {
                pos = i;
                break;
            }
        }

        for i in 12..line.len() {
            let digit = line.chars().nth(i).unwrap().to_digit(10).unwrap() as i64;
            if pos != 11 || digit > v[pos] {
                v.remove(pos);
                v.push(digit);
            }
            pos = 11;
            for i in 0..v.len() - 1 {
                if v[i] < v[i + 1] {
                    pos = i;
                    break;
                }
            }
        }

        let mut line_sol = 0;
        for vi in v.iter() {
            line_sol *= 10;
            line_sol += vi;
        }

        sol += line_sol;
        println!("{}", line_sol);
    }

    println!("Answer: {}", sol);

    Ok(())
}
