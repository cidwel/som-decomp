.setcpu "65816"
.segment "CODE"
.org $6649
map_control_0e6649:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
