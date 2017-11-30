type state = string;

let component = ReasonReact.statefulComponent("Input");

let valueFromEvent = (evt) : string => (
                                         evt
                                         |> ReactEventRe.Form.target
                                         |> ReactDOMRe.domElementToObj
                                       )##value;

let make = (~onSubmit, _) => {
  ...component,
  initialState: () => "",
  render: ({state: text, update}) =>
    <input
      value=text
      _type="text"
      placeholder="Write something to do"
      onChange=(update((evt, _) => ReasonReact.Update(valueFromEvent(evt))))
      onKeyDown=(
        update(
          (evt, {state: text}) =>
            if (ReactEventRe.Keyboard.key(evt) == "Enter") {
              onSubmit(text);
              ReasonReact.Update("")
            } else {
              ReasonReact.NoUpdate
            }
        )
      )
    />
};
