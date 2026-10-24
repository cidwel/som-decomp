.setcpu "65816"
.segment "CODE"
.org $B9F0
map_control_0eb9f0:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
