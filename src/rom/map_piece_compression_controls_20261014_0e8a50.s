.setcpu "65816"
.segment "CODE"
.org $8A50
map_control_0e8a50:
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
