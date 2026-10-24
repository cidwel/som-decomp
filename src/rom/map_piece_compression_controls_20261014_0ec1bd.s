.setcpu "65816"
.segment "CODE"
.org $C1BD
map_control_0ec1bd:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
