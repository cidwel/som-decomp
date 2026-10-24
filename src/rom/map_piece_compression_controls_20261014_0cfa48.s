.setcpu "65816"
.segment "CODE"
.org $FA48
map_control_0cfa48:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
