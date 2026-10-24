.setcpu "65816"
.segment "CODE"
.org $8C22
map_control_0f8c22:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
