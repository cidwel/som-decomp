.setcpu "65816"
.segment "CODE"
.org $7B2D
map_control_0c7b2d:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
