.setcpu "65816"
.segment "CODE"
.org $9DE6
map_control_0d9de6:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
