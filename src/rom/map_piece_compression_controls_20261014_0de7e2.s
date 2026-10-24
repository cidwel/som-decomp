.setcpu "65816"
.segment "CODE"
.org $E7E2
map_control_0de7e2:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
