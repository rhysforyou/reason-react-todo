open Filter;

let component = ReasonReact.statelessComponent("FilterBar");

let se = ReasonReact.stringToElement;

let filterButtonClass = (filter: filter, activeFilter: filter) =>
  filter == activeFilter ? "filter active" : "filter inactive";

let renderFilter = (activeFilter, onChange, filter) => {
  let filterName = displayString(filter);
  <button
    className=(filterButtonClass(filter, activeFilter))
    onClick=((_evt) => onChange(filter))
    key=filterName>
    (se(filterName))
  </button>
};

let renderFilterList = (activeFilter, onChange) =>
  allFilters
  |> List.map(renderFilter(activeFilter, onChange))
  |> Array.of_list
  |> ReasonReact.arrayToElement;

let make = (~activeFilter, ~onChange, _children) => {
  ...component,
  render: (_self) =>
    <div className="filters"> (renderFilterList(activeFilter, onChange)) </div>
};
