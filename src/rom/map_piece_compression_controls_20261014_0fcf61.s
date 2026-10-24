.setcpu "65816"
.segment "CODE"
.org $CF61
map_control_0fcf61:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
