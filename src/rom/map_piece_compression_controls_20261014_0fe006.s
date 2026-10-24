.setcpu "65816"
.segment "CODE"
.org $E006
map_control_0fe006:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
