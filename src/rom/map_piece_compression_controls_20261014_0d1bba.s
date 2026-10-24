.setcpu "65816"
.segment "CODE"
.org $1BBA
map_control_0d1bba:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
