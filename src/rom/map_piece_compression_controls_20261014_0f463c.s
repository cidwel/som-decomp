.setcpu "65816"
.segment "CODE"
.org $463C
map_control_0f463c:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
