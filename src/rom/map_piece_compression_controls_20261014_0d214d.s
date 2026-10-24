.setcpu "65816"
.segment "CODE"
.org $214D
map_control_0d214d:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
