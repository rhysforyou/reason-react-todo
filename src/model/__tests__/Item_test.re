open Item;

open Jest;

let completedItem = {id: 1, title: "First Item", completed: true};

let incompleteItem = {id: 2, title: "Second Item", completed: false};

let noItems = [];

let oneItem = [completedItem];

let twoItems = [completedItem, incompleteItem];

describe(
  "Item",
  () => {
    open Expect;
    describe(
      "itemCount",
      () => {
        test(
          "describes no items",
          () => expect(itemCount(noItems)) |> toBe("No Items")
        );
        test(
          "describes one item",
          () => expect(itemCount(oneItem)) |> toBe("1 Item")
        );
        test(
          "describes two items",
          () => expect(itemCount(twoItems)) |> toBe("2 Items")
        )
      }
    );
    describe(
      "filterItems",
      () => {
        test(
          "filters to all items",
          () => expect(filterItems(Filter.All, twoItems)) |> toEqual(twoItems)
        );
        test(
          "filters to completed items",
          () =>
            expect(filterItems(Filter.Completed, twoItems))
            |> toEqual([completedItem])
        );
        test(
          "filters to incomplete items",
          () =>
            expect(filterItems(Filter.Incomplete, twoItems))
            |> toEqual([incompleteItem])
        )
      }
    );
    describe(
      "toggleCompletion",
      () => {
        test(
          "marks an incomplete item complete",
          () =>
            expect(toggleCompletion([incompleteItem], incompleteItem.id))
            |> toEqual([{id: 2, title: "Second Item", completed: true}])
        );
        test(
          "marks an completed item incomplete",
          () =>
            expect(toggleCompletion([completedItem], completedItem.id))
            |> toEqual([{id: 1, title: "First Item", completed: false}])
        );
        test(
          "does nothing if no item with the ID exists",
          () => expect(toggleCompletion(twoItems, 0)) |> toEqual(twoItems)
        )
      }
    );
    describe(
      "maxId",
      () =>
        test(
          "returns the highest ID in a iten list",
          () => expect(maxId(twoItems)) |> toBe(2)
        )
    );
    describe(
      "nextId",
      () =>
        test(
          "returns the next sequential ID in a iten list",
          () => expect(nextId(twoItems)) |> toBe(3)
        )
    );
    describe(
      "newItem",
      () =>
        test(
          "creates an item with the provided title and the next ID",
          () =>
            expect(newItem(twoItems, "Test"))
            |> toEqual({id: 3, title: "Test", completed: false})
        )
    );
    describe(
      "addItem",
      () =>
        test(
          "adds a new item to the start of the list",
          () =>
            expect(addItem(oneItem, "Second Item"))
            |> toEqual([incompleteItem, completedItem])
        )
    )
  }
);
