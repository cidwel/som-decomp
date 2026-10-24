.setcpu "65816"
.segment "CODE"
.org $F7BD
map_control_0cf7bd:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
