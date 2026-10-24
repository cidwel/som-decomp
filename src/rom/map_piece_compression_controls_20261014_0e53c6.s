.setcpu "65816"
.segment "CODE"
.org $53C6
map_control_0e53c6:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
