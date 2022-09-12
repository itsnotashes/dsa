// Some weird results going on with rust. Where if x < 0.1 and x is incremented by 0.01, random text is printed 11 times. But for x < 0.01 when x is incremented by 0.001, random text is only printed 10 times.

fn main(){
    let mut x: f32 = 0.0;
    while x < 0.1 {
        println!("Random_text");
        x += 0.01;
    }
}