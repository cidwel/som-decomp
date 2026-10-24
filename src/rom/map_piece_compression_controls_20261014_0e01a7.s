.setcpu "65816"
.segment "CODE"
.org $01A7
map_control_0e01a7:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
