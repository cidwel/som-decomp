.setcpu "65816"
.segment "CODE"
.org $1419
map_control_0d1419:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
