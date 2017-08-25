open Filter;

let component = ReasonReact.statelessComponent "FilterBar";
let se = ReasonReact.stringToElement;

let filterButtonClass (filter: filter) (activeFilter: filter) =>
  filter == activeFilter ? "active" : "inactive";

let renderFilter activeFilter onChange filter =>
  <button
    className=(filterButtonClass filter activeFilter)
    onClick=(fun _evt => onChange(filter))>
    (se (displayString filter))
  </button>;

let renderFilterList activeFilter onChange =>
  allFilters
  |> List.map (renderFilter activeFilter onChange)
  |> Array.of_list
  |> ReasonReact.arrayToElement;

let make ::activeFilter ::onChange _children => {
  ...component,
  render: fun _self =>
    <div className="filters">
      (renderFilterList activeFilter onChange)
    </div>
};
