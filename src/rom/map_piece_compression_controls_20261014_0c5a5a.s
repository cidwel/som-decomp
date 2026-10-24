.setcpu "65816"
.segment "CODE"
.org $5A5A
map_control_0c5a5a:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
