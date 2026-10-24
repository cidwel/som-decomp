.setcpu "65816"
.segment "CODE"
.org $78B2
map_control_0d78b2:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
