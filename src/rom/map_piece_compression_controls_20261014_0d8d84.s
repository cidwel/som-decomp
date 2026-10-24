.setcpu "65816"
.segment "CODE"
.org $8D84
map_control_0d8d84:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
