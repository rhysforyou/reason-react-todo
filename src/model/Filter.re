type filter =
  | All
  | Completed
  | Incomplete;

let allFilters = [All, Completed, Incomplete];

let displayString = (filter) =>
  switch filter {
  | All => "All"
  | Completed => "Completed"
  | Incomplete => "Incomplete"
  };
