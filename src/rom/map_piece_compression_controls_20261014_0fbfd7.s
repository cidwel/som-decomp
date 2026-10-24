.setcpu "65816"
.segment "CODE"
.org $BFD7
map_control_0fbfd7:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
