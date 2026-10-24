.setcpu "65816"
.segment "CODE"
.org $4C86
map_control_0d4c86:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
