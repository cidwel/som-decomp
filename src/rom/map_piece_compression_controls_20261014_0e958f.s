.setcpu "65816"
.segment "CODE"
.org $958F
map_control_0e958f:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
