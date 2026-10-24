.setcpu "65816"
.segment "CODE"
.org $73BC
map_control_0f73bc:
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
