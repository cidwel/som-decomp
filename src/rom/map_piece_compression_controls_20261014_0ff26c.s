.setcpu "65816"
.segment "CODE"
.org $F26C
map_control_0ff26c:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
