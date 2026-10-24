.setcpu "65816"
.segment "CODE"
.org $2FF1
map_control_0d2ff1:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
