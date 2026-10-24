.setcpu "65816"
.segment "CODE"
.org $78B4
map_control_0c78b4:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
