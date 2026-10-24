.setcpu "65816"
.segment "CODE"
.org $0A02
map_control_0d0a02:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
