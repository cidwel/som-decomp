.setcpu "65816"
.segment "CODE"
.org $E14D
map_control_0fe14d:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
