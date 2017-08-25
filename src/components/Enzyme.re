type shallowWrapper;
type node = ReasonReact.reactElement;
type selector = string;
type predicate = node => bool;

external shallow : node => shallowWrapper = "" [@@bs.module "enzyme"];
external find : selector => shallowWrapper = "find" [@@bs.send.pipe: shallowWrapper];
external findWhere : predicate => shallowWrapper = "findWhere" [@@bs.send.pipe: shallowWrapper];
external filter : selector => shallowWrapper = "filter" [@@bs.send.pipe: shallowWrapper];
external filterWhere : predicate => shallowWrapper = "filterWhere" [@@bs.send.pipe: shallowWrapper];

external text : shallowWrapper => string = "text" [@@bs.send];
external children : shallowWrapper => shallowWrapper = "children" [@@bs.send];

external getLength : shallowWrapper => int = "length" [@@bs.get];
