.setcpu "65816"
.segment "CODE"
.org $7E48
map_control_0d7e48:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
