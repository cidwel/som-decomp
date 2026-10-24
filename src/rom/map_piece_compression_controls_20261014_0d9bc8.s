.setcpu "65816"
.segment "CODE"
.org $9BC8
map_control_0d9bc8:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
