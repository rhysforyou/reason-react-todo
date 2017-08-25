open Filter;
open Jest;

describe "filter" (fun () => {
  open Expect;

  describe "string_of_filter" (fun () => {
    test "describes the All filter" (fun () =>
      expect (string_of_filter All) |> toBe "All");

    test "describes the Completed filter" (fun () =>
      expect (string_of_filter Completed) |> toBe "Completed");

    test "describes the Incomplete filter" (fun () =>
      expect (string_of_filter Incomplete) |> toBe "Incomplete");
  });
});
