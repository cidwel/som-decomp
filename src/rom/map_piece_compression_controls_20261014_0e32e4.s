.setcpu "65816"
.segment "CODE"
.org $32E4
map_control_0e32e4:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
