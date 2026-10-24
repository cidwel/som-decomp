.setcpu "65816"
.segment "CODE"
.org $C2B5
map_control_0dc2b5:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
