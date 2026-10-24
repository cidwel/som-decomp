.setcpu "65816"
.segment "CODE"
.org $CF75
map_control_0fcf75:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
