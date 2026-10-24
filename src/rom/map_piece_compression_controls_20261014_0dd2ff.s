.setcpu "65816"
.segment "CODE"
.org $D2FF
map_control_0dd2ff:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
