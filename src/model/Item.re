type item = {
  id: int,
  title: string,
  completed: bool
};

let itemCount (items: list item) => {
  let length = List.length items;
  switch length {
  | 0 => "No Items"
  | 1 => "1 Item"
  | _ => string_of_int length ^ " Items"
  }
};

let filterItems filter items =>
  switch filter {
  | Filter.All => items
  | Filter.Completed => List.filter (fun item => item.completed) items
  | Filter.Incomplete => List.filter (fun item => not item.completed) items
  };
