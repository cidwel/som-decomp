.setcpu "65816"
.segment "CODE"
.org $9CD1
map_control_0d9cd1:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
