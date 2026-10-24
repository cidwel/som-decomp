.setcpu "65816"
.segment "CODE"
.org $9CA6
map_control_0f9ca6:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
