.setcpu "65816"
.segment "CODE"
.org $C02A
map_control_0ec02a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
