.setcpu "65816"
.segment "CODE"
.org $B6E4
map_control_0eb6e4:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
