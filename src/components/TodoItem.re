open Item;

let component = ReasonReact.statelessComponent("TodoItem");

let se = ReasonReact.stringToElement;

let make = (~item: item, ~onToggle, _children) => {
  ...component,
  render: (_self) => {
    let id = "todo-" ++ string_of_int(item.id) ++ "-completed";
    <div className="item">
      <input
        id
        _type="checkbox"
        checked=(Js.Boolean.to_js_boolean(item.completed))
        onChange=((_evt) => onToggle(item))
      />
      <label htmlFor=id> (se(item.title)) </label>
    </div>
  }
};
