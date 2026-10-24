.setcpu "65816"
.segment "CODE"
.org $B9C7
map_control_0eb9c7:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
