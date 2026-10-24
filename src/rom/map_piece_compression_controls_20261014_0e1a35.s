.setcpu "65816"
.segment "CODE"
.org $1A35
map_control_0e1a35:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
