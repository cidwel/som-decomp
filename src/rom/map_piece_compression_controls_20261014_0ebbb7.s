.setcpu "65816"
.segment "CODE"
.org $BBB7
map_control_0ebbb7:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
