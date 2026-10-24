.setcpu "65816"
.segment "CODE"
.org $B3FF
map_control_0eb3ff:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
