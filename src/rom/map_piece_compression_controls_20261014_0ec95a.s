.setcpu "65816"
.segment "CODE"
.org $C95A
map_control_0ec95a:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
