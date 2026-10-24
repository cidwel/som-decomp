.setcpu "65816"
.segment "CODE"
.org $0A3C
map_control_0d0a3c:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
