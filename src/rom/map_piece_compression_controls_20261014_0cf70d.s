.setcpu "65816"
.segment "CODE"
.org $F70D
map_control_0cf70d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
