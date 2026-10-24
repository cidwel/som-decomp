; Typed pointer fields; docs/native-indirect-table-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E902
native_event_wait_state_targets:
    .word $F2E9, $F2F5, $F310, $F31C, $F341, $F348, $F37B, $F389, $F389, $F389, $F389, $F389, $F389, $F389, $F389, $F389
