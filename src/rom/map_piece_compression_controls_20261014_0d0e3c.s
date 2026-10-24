.setcpu "65816"
.segment "CODE"
.org $0E3C
map_control_0d0e3c:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
