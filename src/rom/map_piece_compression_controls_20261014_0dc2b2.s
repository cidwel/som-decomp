.setcpu "65816"
.segment "CODE"
.org $C2B2
map_control_0dc2b2:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
