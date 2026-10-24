.setcpu "65816"
.segment "CODE"
.org $5C5A
map_control_0f5c5a:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
