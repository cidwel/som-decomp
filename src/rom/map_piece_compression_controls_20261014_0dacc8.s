.setcpu "65816"
.segment "CODE"
.org $ACC8
map_control_0dacc8:
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
