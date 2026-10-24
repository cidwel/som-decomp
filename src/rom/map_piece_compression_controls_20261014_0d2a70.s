.setcpu "65816"
.segment "CODE"
.org $2A70
map_control_0d2a70:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
