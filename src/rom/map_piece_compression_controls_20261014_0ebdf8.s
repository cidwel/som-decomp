.setcpu "65816"
.segment "CODE"
.org $BDF8
map_control_0ebdf8:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
