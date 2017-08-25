type filter =
  | All
  | Completed
  | Incomplete;

let string_of_filter filter =>
  switch filter {
  | All => "All"
  | Completed => "Completed"
  | Incomplete => "Incomplete"
  };
