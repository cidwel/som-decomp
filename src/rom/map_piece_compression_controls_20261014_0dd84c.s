.setcpu "65816"
.segment "CODE"
.org $D84C
map_control_0dd84c:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
