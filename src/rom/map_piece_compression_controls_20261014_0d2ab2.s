.setcpu "65816"
.segment "CODE"
.org $2AB2
map_control_0d2ab2:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
