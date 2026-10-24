.setcpu "65816"
.segment "CODE"
.org $C95E
map_control_0ec95e:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
