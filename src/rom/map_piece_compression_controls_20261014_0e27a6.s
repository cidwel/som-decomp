.setcpu "65816"
.segment "CODE"
.org $27A6
map_control_0e27a6:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
