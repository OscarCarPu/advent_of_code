use std::collections::HashSet;
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
    let mut invalid_ids: HashSet<u128> = HashSet::new();
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
                for k in 2..=len {
                    if len % k == 0 {
                        let sub_len = (len / k) as u32;

                        let mut multiplier: u128 = 0;
                        for i in 0..k {
                            multiplier += base.pow((i as u32) * sub_len);
                        }

                        let root_min_limit = base.pow(sub_len - 1);
                        let root_max_limit = base.pow(sub_len) - 1;

                        let mut p_start = start_val / multiplier;
                        if p_start * multiplier < start_val {
                            p_start += 1;
                        }

                        let p_end = end_val / multiplier;

                        let search_start = p_start.max(root_min_limit);
                        let search_end = p_end.min(root_max_limit);

                        if search_start <= search_end {
                            for p in search_start..=search_end {
                                invalid_ids.insert(p * multiplier);
                            }
                        }
                    }
                }
            }
        }
    }

    let total_sum: u128 = invalid_ids.iter().sum();
    println!("Answer: {}", total_sum);

    Ok(())
}
