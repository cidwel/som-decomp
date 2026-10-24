.setcpu "65816"
.segment "CODE"
.org $12A3
map_control_0e12a3:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
