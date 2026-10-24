.setcpu "65816"
.segment "CODE"
.org $56CB
map_control_0c56cb:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
