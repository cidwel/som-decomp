.setcpu "65816"
.segment "CODE"
.org $6F17
map_control_0f6f17:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
