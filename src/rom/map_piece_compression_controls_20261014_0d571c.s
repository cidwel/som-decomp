.setcpu "65816"
.segment "CODE"
.org $571C
map_control_0d571c:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
