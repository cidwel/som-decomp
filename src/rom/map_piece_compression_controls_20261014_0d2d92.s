.setcpu "65816"
.segment "CODE"
.org $2D92
map_control_0d2d92:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
