.setcpu "65816"
.segment "CODE"
.org $9377
map_control_0e9377:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
