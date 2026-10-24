.setcpu "65816"
.segment "CODE"
.org $451F
map_control_0e451f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
