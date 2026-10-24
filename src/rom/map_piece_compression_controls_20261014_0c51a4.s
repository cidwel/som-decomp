.setcpu "65816"
.segment "CODE"
.org $51A4
map_control_0c51a4:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
