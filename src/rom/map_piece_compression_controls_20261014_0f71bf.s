.setcpu "65816"
.segment "CODE"
.org $71BF
map_control_0f71bf:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
