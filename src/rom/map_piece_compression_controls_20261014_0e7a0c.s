.setcpu "65816"
.segment "CODE"
.org $7A0C
map_control_0e7a0c:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
