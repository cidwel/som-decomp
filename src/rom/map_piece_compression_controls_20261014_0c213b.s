.setcpu "65816"
.segment "CODE"
.org $213B
map_control_0c213b:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
