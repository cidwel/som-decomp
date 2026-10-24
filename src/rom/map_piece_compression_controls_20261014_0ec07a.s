.setcpu "65816"
.segment "CODE"
.org $C07A
map_control_0ec07a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
