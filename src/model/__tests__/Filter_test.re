open Filter;

open Jest;

describe(
  "Filter",
  () =>
    Expect.(
      describe(
        "displayString",
        () => {
          test(
            "describes the All filter",
            () => expect(displayString(All)) |> toBe("All")
          );
          test(
            "describes the Completed filter",
            () => expect(displayString(Completed)) |> toBe("Completed")
          );
          test(
            "describes the Incomplete filter",
            () => expect(displayString(Incomplete)) |> toBe("Incomplete")
          )
        }
      )
    )
);
