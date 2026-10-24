.setcpu "65816"
.segment "CODE"
.org $1B25
map_control_0c1b25:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
