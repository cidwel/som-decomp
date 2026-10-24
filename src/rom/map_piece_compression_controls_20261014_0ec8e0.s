.setcpu "65816"
.segment "CODE"
.org $C8E0
map_control_0ec8e0:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
