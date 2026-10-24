.setcpu "65816"
.segment "CODE"
.org $9C02
map_control_0d9c02:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
