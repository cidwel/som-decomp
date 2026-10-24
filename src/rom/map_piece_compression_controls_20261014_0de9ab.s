.setcpu "65816"
.segment "CODE"
.org $E9AB
map_control_0de9ab:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
