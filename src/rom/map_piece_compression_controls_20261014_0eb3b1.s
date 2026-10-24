.setcpu "65816"
.segment "CODE"
.org $B3B1
map_control_0eb3b1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
