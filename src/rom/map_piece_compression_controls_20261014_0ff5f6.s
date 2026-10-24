.setcpu "65816"
.segment "CODE"
.org $F5F6
map_control_0ff5f6:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
