.setcpu "65816"
.segment "CODE"
.org $0E68
map_control_0f0e68:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
