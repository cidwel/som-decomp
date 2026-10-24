.setcpu "65816"
.segment "CODE"
.org $6DFB
map_control_0d6dfb:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
