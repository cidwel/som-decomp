.setcpu "65816"
.segment "CODE"
.org $F668
map_control_0df668:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
