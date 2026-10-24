.setcpu "65816"
.segment "CODE"
.org $9577
map_control_0e9577:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
