struct Node {
    data: i32,
    next: Option<Box<Node>>,
}

struct Linkedlist {
    head: Option<Box<Node>>,
}

impl Linkedlist {
    fn new() -> Linkedlist {
        Linkedlist {head: None}
    }

    fn add(&mut self, data: i32){
        let new_node = Node {
            data: data, 
            next: None,
        };

        let mut current_node = &mut self.head;

        loop {
            match current_node {
                None => {
                    *current_node = Some(Box::new(new_node));
                    break;
                }

                Some(node) => {
                    current_node = &mut node.next;
                }
            }
        }
    }

    fn print(&self) {
        let mut current_node = &self.head;

        loop {
            match current_node {
                None => {
                    break;
                }
                Some(node) => {
                    println!("{}", node.data);
                    current_node = &node.next;
                }
            }
        }
    }

}


fn main(){
    let mut linked_list = Linkedlist::new();

    linked_list.add(1);
    linked_list.add(2);
    linked_list.add(3);
    linked_list.add(4);
    linked_list.add(5);
    linked_list.add(6);

    linked_list.print()

}