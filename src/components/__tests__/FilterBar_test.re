open Jest;

let setup = (~activeFilter=Filter.All, ~onChange=(_filter) => (), ()) =>
  Enzyme.shallow(<FilterBar activeFilter onChange />);

let filters = (wrapper) =>
  wrapper |> Enzyme.find(".filters") |> Enzyme.children;

let activeFilters = (wrapper) => wrapper |> filters |> Enzyme.find(".active");

let inactiveFilters = (wrapper) =>
  wrapper |> filters |> Enzyme.find(".inactive");

describe(
  "FilterBar",
  () =>
    Expect.(
      describe(
        "when the active filter is 'All'",
        () => {
          let wrapper = setup(~activeFilter=Filter.All, ());
          test(
            "renders All with the .active class",
            () => {
              let activeFilterText = wrapper |> activeFilters |> Enzyme.text;
              expect(activeFilterText) |> toContainString("All")
            }
          );
          test(
            "only renders one active filter",
            () => {
              open! Expect.Operators;
              let activeFilterCount =
                wrapper |> activeFilters |> Enzyme.length;
              expect(activeFilterCount) == 1
            }
          );
          test(
            "renders the other two filters with the .inactive class",
            () => {
              open! Expect.Operators;
              let inactiveCount = wrapper |> inactiveFilters |> Enzyme.length;
              expect(inactiveCount) == 2
            }
          );
          test(
            "calls its onChange handler when a filter is clicked",
            () => {
              let wasCalled = ref(false);
              let wrapper =
                setup(~onChange=(_filter) => wasCalled := true, ());
              wrapper |> filters |> Enzyme.first |> Enzyme.simulate("click");
              expect(wasCalled^) |> toBe(true)
            }
          )
        }
      )
    )
);
