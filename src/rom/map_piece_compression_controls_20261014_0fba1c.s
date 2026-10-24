.setcpu "65816"
.segment "CODE"
.org $BA1C
map_control_0fba1c:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
