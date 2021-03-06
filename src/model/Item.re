type item = {
  id: int,
  title: string,
  completed: bool
};

let itemCount = (items: list(item)) => {
  let length = List.length(items);
  switch length {
  | 0 => "No Items"
  | 1 => "1 Item"
  | _ => string_of_int(length) ++ " Items"
  }
};

let filterItems = (filter, items) =>
  switch filter {
  | Filter.All => items
  | Filter.Completed => List.filter((item) => item.completed, items)
  | Filter.Incomplete => List.filter((item) => ! item.completed, items)
  };

let toggleCompletion = (items, id) =>
  List.map(
    (item) => item.id === id ? {...item, completed: ! item.completed} : item,
    items
  );

let maxId = (items) =>
  List.fold_left((max, item) => item.id > max ? item.id : max, 0, items);

let nextId = (items) => maxId(items) + 1;

let newItem = (items, title) => {title, id: nextId(items), completed: false};

let addItem = (items, title) => [newItem(items, title), ...items];
