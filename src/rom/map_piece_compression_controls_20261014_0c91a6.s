.setcpu "65816"
.segment "CODE"
.org $91A6
map_control_0c91a6:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
