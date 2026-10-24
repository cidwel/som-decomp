.setcpu "65816"
.segment "CODE"
.org $1F0C
map_control_0e1f0c:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
