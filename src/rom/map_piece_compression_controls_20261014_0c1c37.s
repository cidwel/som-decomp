.setcpu "65816"
.segment "CODE"
.org $1C37
map_control_0c1c37:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
