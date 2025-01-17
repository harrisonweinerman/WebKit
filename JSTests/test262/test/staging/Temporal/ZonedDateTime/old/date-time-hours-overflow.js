// Copyright (C) 2018 Bloomberg LP. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
esid: sec-temporal-zoneddatetime-objects
description: hours overflow
features: [Temporal]
---*/


// subtract result
var later = Temporal.ZonedDateTime.from("2019-10-29T10:46:38.271986102-03:00[America/Santiago]");
var earlier = later.subtract({ hours: 12 });
assert.sameValue(`${ earlier }`, "2019-10-28T22:46:38.271986102-03:00[America/Santiago]");

// add result
var earlier = Temporal.ZonedDateTime.from("2020-05-31T23:12:38.271986102-04:00[America/Santiago]");
var later = earlier.add({ hours: 2 });
assert.sameValue(`${ later }`, "2020-06-01T01:12:38.271986102-04:00[America/Santiago]");

// symmetrical with regard to negative durations
assert.sameValue(`${ Temporal.ZonedDateTime.from("2019-10-29T10:46:38.271986102-03:00[America/Santiago]").add({ hours: -12 }) }`, "2019-10-28T22:46:38.271986102-03:00[America/Santiago]");
assert.sameValue(`${ Temporal.ZonedDateTime.from("2020-05-31T23:12:38.271986102-04:00[America/Santiago]").subtract({ hours: -2 }) }`, "2020-06-01T01:12:38.271986102-04:00[America/Santiago]");
