.setcpu "65816"
.segment "CODE"
.org $B3F3
map_control_0eb3f3:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
