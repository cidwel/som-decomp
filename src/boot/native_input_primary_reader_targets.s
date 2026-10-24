; Typed pointer fields; docs/native-indirect-table-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A60D
native_input_primary_reader_targets:
    .word $A573, $A5A4, $A5B2, $A603
