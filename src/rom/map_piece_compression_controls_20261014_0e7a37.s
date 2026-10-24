.setcpu "65816"
.segment "CODE"
.org $7A37
map_control_0e7a37:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
