.setcpu "65816"
.segment "CODE"
.org $2A7E
map_control_0d2a7e:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
