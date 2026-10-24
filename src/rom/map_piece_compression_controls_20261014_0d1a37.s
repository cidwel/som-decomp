.setcpu "65816"
.segment "CODE"
.org $1A37
map_control_0d1a37:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
