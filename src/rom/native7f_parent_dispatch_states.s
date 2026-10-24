; Numeric Native7F state selectors; docs/boss-native7f-header.md.
.setcpu "65816"
.segment "CODE"
.org $8F51
native7f_parent_dispatch_states:
    .word $8F7B, $8FB3, $9027, $904E, $90AC, $910E, $917F, $91A4
    .word $924B, $92A8, $92F6, $9381, $9463, $9499, $94BE, $9539
    .word $95BD, $964B, $96A5, $96F8, $977B
