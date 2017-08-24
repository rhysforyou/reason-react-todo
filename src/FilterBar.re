open Types;

let component = ReasonReact.statelessComponent "FilterBar";
let se = ReasonReact.stringToElement;

let filterButtonClass (filter: filter) (activeFilter: filter) =>
  filter == activeFilter ? "active" : "inactive";

let make ::activeFilter ::onChange _children => {
  ...component,
  render: fun _self =>
    <div className="filters">
      <button
        className=(filterButtonClass All activeFilter)
        onClick=(fun _evt => onChange(All))>
        (se "All")
      </button>
      <button
        className=(filterButtonClass Completed activeFilter)
        onClick=(fun _evt => onChange(Completed))>
        (se "Completed")
      </button>
      <button
        className=(filterButtonClass Incomplete activeFilter)
        onClick=(fun _evt => onChange(Incomplete))>
        (se "Incomplete")
      </button>
    </div>
};
