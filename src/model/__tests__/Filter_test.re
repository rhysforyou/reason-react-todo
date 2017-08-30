open Filter;
open Jest;

describe "Filter" (fun () => {
  open Expect;

  describe "displayString" (fun () => {
    test "describes the All filter" (fun () =>
      expect (displayString All) |> toBe "All");

    test "describes the Completed filter" (fun () =>
      expect (displayString Completed) |> toBe "Completed");

    test "describes the Incomplete filter" (fun () =>
      expect (displayString Incomplete) |> toBe "Incomplete");
  });
});
