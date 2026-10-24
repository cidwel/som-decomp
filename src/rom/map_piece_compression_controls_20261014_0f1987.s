.setcpu "65816"
.segment "CODE"
.org $1987
map_control_0f1987:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
