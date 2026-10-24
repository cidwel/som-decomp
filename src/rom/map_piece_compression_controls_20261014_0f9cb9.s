.setcpu "65816"
.segment "CODE"
.org $9CB9
map_control_0f9cb9:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
