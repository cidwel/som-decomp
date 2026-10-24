.setcpu "65816"
.segment "CODE"
.org $C1AB
map_control_0ec1ab:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
