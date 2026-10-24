.setcpu "65816"
.segment "CODE"
.org $C96C
map_control_0ec96c:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
