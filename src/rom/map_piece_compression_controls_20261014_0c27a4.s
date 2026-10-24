.setcpu "65816"
.segment "CODE"
.org $27A4
map_control_0c27a4:
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
