.setcpu "65816"
.segment "CODE"
.org $AEC5
map_control_0eaec5:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
