.setcpu "65816"
.segment "CODE"
.org $5278
map_control_0c5278:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
