.setcpu "65816"
.segment "CODE"
.org $F7A4
map_control_0cf7a4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
