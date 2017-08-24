open Item;
open Jest;

let completedItem = {id: 1, title: "First Item", completed: true};
let incompleteItem = {id: 2, title: "Second Item", completed: false};

let noItems = [];
let oneItem = [completedItem];
let twoItems = [completedItem, incompleteItem];

describe "Item" (fun () => {
  open Expect;

  describe "itemCount" (fun () => {
    test "describes no items" (fun () =>
      expect (itemCount noItems) |> toBe "No Items");

    test "describes one item" (fun () =>
      expect (itemCount oneItem) |> toBe "1 Item");

    test "describes two items" (fun () =>
      expect (itemCount twoItems) |> toBe "2 Items");
  });

  describe "filterItems" (fun () => {
    test "filters to all items" (fun () =>
      expect (filterItems Filter.All twoItems) |> toEqual twoItems);

    test "filters to completed items" (fun () =>
      expect (filterItems Filter.Completed twoItems) |> toEqual [completedItem]);

    test "filters to incomplete items" (fun () =>
      expect (filterItems Filter.Incomplete twoItems) |> toEqual [incompleteItem]);
  });

  describe "toggleCompletion" (fun () => {
    test "marks an incomplete item complete" (fun () =>
      expect (toggleCompletion [incompleteItem] incompleteItem.id)
        |> toEqual [{id: 2, title: "Second Item", completed: true}]);

    test "marks an completed item incomplete" (fun () =>
      expect (toggleCompletion [completedItem] completedItem.id)
        |> toEqual [{id: 1, title: "First Item", completed: false}]);

    test "does nothing if no item with the ID exists" (fun () =>
      expect (toggleCompletion twoItems 0) |> toEqual twoItems)
  });
});
