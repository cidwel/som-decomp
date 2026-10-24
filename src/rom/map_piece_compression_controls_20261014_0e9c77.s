.setcpu "65816"
.segment "CODE"
.org $9C77
map_control_0e9c77:
    .byte $E8 ; backreference distance high bits
    .byte $2B ; distance low bit/count
