let se = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TodoList");

let renderItem = (onToggle, item: Item.item) =>
  <TodoItem item onToggle key=(string_of_int(item.id)) />;

let renderItemList = (onToggle, items) =>
  items
  |> List.map(renderItem(onToggle))
  |> Array.of_list
  |> ReasonReact.arrayToElement;

let make = (~onToggle, ~items, _children) => {
  ...component,
  render: (_self) =>
    <div className="items"> (renderItemList(onToggle, items)) </div>
};
