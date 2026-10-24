.setcpu "65816"
.segment "CODE"
.org $8593
map_control_0f8593:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
