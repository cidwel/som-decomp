.setcpu "65816"
.segment "CODE"
.org $78F6
map_control_0d78f6:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
