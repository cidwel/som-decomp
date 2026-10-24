.setcpu "65816"
.segment "CODE"
.org $1EA9
map_control_0e1ea9:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
