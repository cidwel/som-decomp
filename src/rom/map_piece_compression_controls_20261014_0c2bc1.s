.setcpu "65816"
.segment "CODE"
.org $2BC1
map_control_0c2bc1:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
