open Types;

type state = {
  items: list item,
  filter
};

type self = ReasonReact.self state ReasonReact.noRetainedProps;

let se = ReasonReact.stringToElement;

let component = ReasonReact.statefulComponent "TodoApp";

let lastId = ref 0;
let addItem text ({state}: self) => {
  lastId := !lastId + 1;
  ReasonReact.Update {
    ...state,
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

let toggleItem {id} ({state}: self) => {
  ReasonReact.Update {
    ...state,
    items: List.map
      (fun item => item.id === id
        ? {...item, completed: not item.completed}
        : item
      )
      state.items
  }
};

let setFilter filter ({state}: self) =>
  ReasonReact.Update {
    ...state,
    filter: filter
  };

let filterItems filter items =>
  switch filter {
  | All => items
  | Completed =>
    List.filter (fun item => item.completed) items
  | Incomplete =>
    List.filter (fun item => not item.completed) items
  };

let renderItem update item =>
    <TodoItem
      item
      onToggle=(update toggleItem)
      key=(string_of_int item.id) />;

let renderItemList update items =>
  items
  |> List.map (renderItem update)
  |> Array.of_list
  |> ReasonReact.arrayToElement;

let itemCount items => {
  let length = List.length items;
  switch length {
  | 0 => "No Items"
  | 1 => "1 Item"
  | _ => string_of_int length ^ " items"
  }
};

let make _children => {
  ...component,
  initialState: fun () => {
    items: [{
      id: 0,
      title: "Write some things to do",
      completed: false
    }],
    filter: All
  },
  render: fun {state: {items, filter}, update} => {
    let filteredItems = filterItems filter items;
    <div className="app">
      <div className="title">
        (se "What to do")
        <Input onSubmit=(update addItem) />
        <FilterBar
          activeFilter=(filter)
          onChange=(update setFilter) />
      </div>
      <div className="items"> (renderItemList update filteredItems) </div>
      <div className="footer">
        (se (itemCount filteredItems))
      </div>
    </div>
  }
};
