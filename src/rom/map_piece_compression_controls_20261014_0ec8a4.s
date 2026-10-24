.setcpu "65816"
.segment "CODE"
.org $C8A4
map_control_0ec8a4:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
