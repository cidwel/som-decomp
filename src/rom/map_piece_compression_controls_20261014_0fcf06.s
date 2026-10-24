.setcpu "65816"
.segment "CODE"
.org $CF06
map_control_0fcf06:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
