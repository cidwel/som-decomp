.setcpu "65816"
.segment "CODE"
.org $FAED
map_control_0cfaed:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
