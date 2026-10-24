.setcpu "65816"
.segment "CODE"
.org $6B3C
map_control_0c6b3c:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
