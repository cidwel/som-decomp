.setcpu "65816"
.segment "CODE"
.org $E5B2
map_control_0de5b2:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
