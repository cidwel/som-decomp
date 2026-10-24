.setcpu "65816"
.segment "CODE"
.org $55CF
map_control_0e55cf:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
