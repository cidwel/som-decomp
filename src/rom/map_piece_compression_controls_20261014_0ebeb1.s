.setcpu "65816"
.segment "CODE"
.org $BEB1
map_control_0ebeb1:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
