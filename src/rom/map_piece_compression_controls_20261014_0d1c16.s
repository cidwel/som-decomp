.setcpu "65816"
.segment "CODE"
.org $1C16
map_control_0d1c16:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
