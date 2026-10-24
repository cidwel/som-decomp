.setcpu "65816"
.segment "CODE"
.org $8FCE
map_control_0c8fce:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
