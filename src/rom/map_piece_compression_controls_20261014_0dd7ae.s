.setcpu "65816"
.segment "CODE"
.org $D7AE
map_control_0dd7ae:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
