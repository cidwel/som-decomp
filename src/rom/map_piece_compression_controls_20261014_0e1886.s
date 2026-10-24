.setcpu "65816"
.segment "CODE"
.org $1886
map_control_0e1886:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
