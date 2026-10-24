.setcpu "65816"
.segment "CODE"
.org $B9EC
map_control_0eb9ec:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
