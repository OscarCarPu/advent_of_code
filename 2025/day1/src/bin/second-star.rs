use std::fs::File;
use std::io::{self, BufReader, BufRead};
use std::process;

fn main() -> io::Result<()> {
    let mut cnt: i64 = 0;
    let mut initial: i64 = 50;

    let filename = "input.txt";

    let file = match File::open(filename) {
        Ok(f) => f,
        Err(_) => {
            process::exit(1);
        }
    };

    let reader = BufReader::new(file);

    for line_result in reader.lines() {
        let line = match line_result {
            Ok(l) => l,
            Err(_) => continue
        };

        let direction = line.chars().next().unwrap();
        let value_str = &line[1..];

        let mut value: i64 = match value_str.parse() {
            Ok(v) => v,
            Err(_) => continue
        };

        let end;

        cnt += value / 100;
        value= value % 100;

        if direction == 'L' {
            end = (initial - value % 100 + 100) % 100;
        } else {
            end = (initial + value) % 100;
        }

        if direction == 'L' && (end > initial || end ==0) && initial != 0{
            cnt += 1;
        }
        if direction == 'R' && (end < initial) && initial != 0{
            cnt += 1;
        }
        initial = end;
    }
    println!("{}", cnt);

    Ok(())
}
