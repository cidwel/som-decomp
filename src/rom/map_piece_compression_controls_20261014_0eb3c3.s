.setcpu "65816"
.segment "CODE"
.org $B3C3
map_control_0eb3c3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
