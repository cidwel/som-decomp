.setcpu "65816"
.segment "CODE"
.org $9121
map_control_0c9121:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
