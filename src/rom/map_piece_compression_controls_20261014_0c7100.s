.setcpu "65816"
.segment "CODE"
.org $7100
map_control_0c7100:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
