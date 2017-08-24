open Item;
open Jest;

let completedItem = {id: 1, title: "First Item", completed: true};
let incompleteItem = {id: 2, title: "Second Item", completed: false};

let noItems = [];
let oneItem = [completedItem];
let twoItems = [completedItem, incompleteItem];

describe "Item" (fun () => {
  describe "itemCount" (fun () => {
    open Expect;

    test "describes no items" (fun () =>
      expect (itemCount noItems) |> toBe "No Items");

    test "describes one item" (fun () =>
      expect (itemCount oneItem) |> toBe "1 Item");

    test "describes two items" (fun () =>
      expect (itemCount twoItems) |> toBe "2 Items");
  });

  describe "filterItems" (fun () => {
    open Expect;

    test "filters to all items" (fun () =>
      expect (filterItems Filter.All twoItems) |> toEqual twoItems);

    test "filters to completed items" (fun () =>
      expect (filterItems Filter.Completed twoItems) |> toEqual [completedItem]);

    test "filters to incomplete items" (fun () =>
      expect (filterItems Filter.Incomplete twoItems) |> toEqual [incompleteItem]);
  });
});
