let se = ReasonReact.stringToElement;
let component = ReasonReact.statelessComponent "TodoItem";

type item = {
  id: int,
  title: string,
  completed: bool,
};

let make item::(item: item) ::onToggle _children => {
  ...component,
  render: fun _self => {
    let id = "todo-" ^ (string_of_int item.id) ^ "-completed";
    <div className="item">
      <input
        id
        _type="checkbox"
        checked=(Js.Boolean.to_js_boolean item.completed)
        onChange=(fun _evt => (onToggle item))
      />
      <label htmlFor=(id)>(se item.title)</label>
    </div>
  }
};
