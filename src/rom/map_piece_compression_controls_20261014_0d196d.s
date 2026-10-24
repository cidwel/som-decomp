.setcpu "65816"
.segment "CODE"
.org $196D
map_control_0d196d:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
