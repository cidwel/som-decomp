.setcpu "65816"
.segment "CODE"
.org $C1C1
map_control_0ec1c1:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
