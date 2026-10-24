.setcpu "65816"
.segment "CODE"
.org $1198
map_control_0f1198:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
