.setcpu "65816"
.segment "CODE"
.org $2720
map_control_0c2720:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
