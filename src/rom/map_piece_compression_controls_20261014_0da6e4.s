.setcpu "65816"
.segment "CODE"
.org $A6E4
map_control_0da6e4:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
