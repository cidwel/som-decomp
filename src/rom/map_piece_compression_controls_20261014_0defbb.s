.setcpu "65816"
.segment "CODE"
.org $EFBB
map_control_0defbb:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
