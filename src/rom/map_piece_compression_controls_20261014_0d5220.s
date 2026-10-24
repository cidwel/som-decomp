.setcpu "65816"
.segment "CODE"
.org $5220
map_control_0d5220:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
