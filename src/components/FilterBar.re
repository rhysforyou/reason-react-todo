open Filter;

let component = ReasonReact.statelessComponent "FilterBar";
let se = ReasonReact.stringToElement;

let filterButtonClass (filter: filter) (activeFilter: filter) =>
  filter == activeFilter ? "active" : "inactive";

let make ::activeFilter ::onChange _children => {
  ...component,
  render: fun _self =>
    <div className="filters">
      (
        [All, Completed, Incomplete]
        |> List.map (fun filter =>
            <button
              className=(filterButtonClass filter activeFilter)
              onClick=(fun _evt => onChange(filter))>
              (se (string_of_filter filter))
            </button>
          )
        |> Array.of_list
        |> ReasonReact.arrayToElement
      )
    </div>
};
