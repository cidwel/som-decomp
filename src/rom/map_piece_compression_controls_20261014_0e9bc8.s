.setcpu "65816"
.segment "CODE"
.org $9BC8
map_control_0e9bc8:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
