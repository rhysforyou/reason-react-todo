open Jest;

let setup ::activeFilter=(Filter.All) ::onChange=(fun _filter => ()) () =>
  Enzyme.shallow <FilterBar activeFilter onChange />;

let filters wrapper =>
  wrapper
  |> Enzyme.find ".filters"
  |> Enzyme.children;

let activeFilters wrapper =>
  wrapper
  |> filters
  |> Enzyme.find ".active";

let inactiveFilters wrapper =>
  wrapper
  |> filters
  |> Enzyme.find ".inactive";

describe "FilterBar" (fun () => {
  open Expect;

  describe "when the active filter is 'All'" (fun () => {
    let wrapper = setup activeFilter::Filter.All ();

    test "renders All with the .active class" (fun () => {
      let activeFilterText = wrapper |> activeFilters |> Enzyme.text;
      expect activeFilterText |> toContainString "All";
    });

    test "only renders one active filter" (fun () => {
      open! Expect.Operators;
      let activeFilterCount = wrapper |> activeFilters |> Enzyme.getLength;
      expect activeFilterCount == 1;
    });

    test "renders the other two filters with the .inactive class" (fun () => {
      open! Expect.Operators;
      let inactiveCount = wrapper |> inactiveFilters |> Enzyme.getLength;
      expect inactiveCount == 2;
    });

    test "calls its onChange handler when a filter is clicked" (fun () => {
      let wasCalled = ref false;
      let wrapper = setup onChange::(fun _filter => wasCalled := true) ();
      wrapper |> filters |> Enzyme.first |> Enzyme.simulate "click";

      expect !wasCalled |> toBe true;
    });
  });
});
