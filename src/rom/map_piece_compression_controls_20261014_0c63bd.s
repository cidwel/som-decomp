.setcpu "65816"
.segment "CODE"
.org $63BD
map_control_0c63bd:
    .byte $E8 ; backreference distance high bits
    .byte $46 ; distance low bit/count
