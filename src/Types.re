type item = {
  id: int,
  title: string,
  completed: bool
};

type filter =
  | All
  | Completed
  | Incomplete;
