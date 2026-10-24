.setcpu "65816"
.segment "CODE"
.org $1CC6
map_control_0e1cc6:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
