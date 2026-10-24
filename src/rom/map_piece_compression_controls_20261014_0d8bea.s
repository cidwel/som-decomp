.setcpu "65816"
.segment "CODE"
.org $8BEA
map_control_0d8bea:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
