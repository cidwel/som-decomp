.setcpu "65816"
.segment "CODE"
.org $E831
map_control_0fe831:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
