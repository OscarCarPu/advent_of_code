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
    let mut total_sum: u128 = 0;
    let base: u128 = 10;

    if let Some(line_result) = reader.lines().next() {
        let line = line_result?;

        for range in line.split(',') {
            let parts: Vec<&str> = range.split('-').collect();

            let start_str = parts[0];
            let end_str = parts[1];

            let min_len = start_str.len();
            let max_len = end_str.len();

            let start_val: u128 = start_str.parse().expect("too big");
            let end_val: u128 = end_str.parse().expect("too big");

            for len in min_len..=max_len {
                if len % 2 != 0 {
                    continue;
                }

                let half_len = (len / 2) as u32;

                let multiplier = base.pow(half_len) + 1;

                let mut root_min = base.pow(half_len - 1);
                let mut root_max = base.pow(half_len) - 1;

                if len == min_len {
                    let prefix_str = &start_str[0..half_len as usize];
                    let prefix: u128 = prefix_str.parse().unwrap();

                    let constructed = prefix * multiplier;

                    if constructed < start_val {
                        root_min = root_min.max(prefix + 1);
                    } else {
                        root_min = root_min.max(prefix);
                    }
                }

                if len == max_len {
                    let prefix_str = &end_str[0..half_len as usize];
                    let prefix: u128 = prefix_str.parse().unwrap();

                    let constructed = prefix * multiplier;

                    if constructed > end_val {
                        root_max = root_max.min(prefix - 1);
                    } else {
                        root_max = root_max.min(prefix);
                    }
                }

                if root_min <= root_max {
                    let count = root_max - root_min + 1;

                    let sum_of_roots = (root_min + root_max) * count / 2;

                    total_sum += sum_of_roots * multiplier;
                }
            }
        }
    }

    println!("Answer: {}", total_sum);

    Ok(())
}
