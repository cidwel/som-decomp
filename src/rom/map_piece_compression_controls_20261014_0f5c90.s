.setcpu "65816"
.segment "CODE"
.org $5C90
map_control_0f5c90:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
