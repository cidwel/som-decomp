.setcpu "65816"
.segment "CODE"
.org $2AA4
map_control_0d2aa4:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
