.setcpu "65816"
.segment "CODE"
.org $B6F4
map_control_0eb6f4:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
