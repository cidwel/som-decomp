.setcpu "65816"
.segment "CODE"
.org $3278
map_control_0e3278:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
