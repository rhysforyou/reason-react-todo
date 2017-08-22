type state = {
  items: list TodoItem.item,
};

type self = ReasonReact.self state ReasonReact.noRetainedProps;

let se = ReasonReact.stringToElement;

let component = ReasonReact.statefulComponent "TodoApp";

let itemCount items => {
  let length = List.length items;
  switch length {
  | 0 => "No Items"
  | 1 => "1 Item"
  | _ => string_of_int length ^ " items"
  }
};

let lastId = ref 0;
let addItem text ({state}: self) => {
  lastId := !lastId + 1;
  ReasonReact.Update {
    items: [
      {
        id: !lastId,
        title: text,
        completed: false
      },
      ...state.items
    ]
  };
};

let toggleItem ({id}: TodoItem.item) ({state}: self) => {
  ReasonReact.Update {
    items: List.map
      (fun (item: TodoItem.item) => item.id === id
        ? {...item, completed: not item.completed}
        : item
      )
      state.items
  }
};

let renderItems items update =>
  items
  |> List.map (fun (item: TodoItem.item) =>
      <TodoItem
      item
      onToggle=(update toggleItem)
      key=(string_of_int item.id) />
    )
  |> Array.of_list
  |> ReasonReact.arrayToElement;

let make _children => {
  ...component,
  initialState: fun () => {
    items: [{
      id: 0,
      title: "Write some things to do",
      completed: false
    }]
  },
  render: fun {state: {items}, update} =>
    <div className="app">
      <div className="title">
        (se "What to do")
        (se "What to do")
        <Input onSubmit=(update addItem) />
      </div>
      <div className="items"> (renderItems items update) </div>
      <div className="footer"> (se (itemCount items)) </div>
    </div>
};
