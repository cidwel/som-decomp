.setcpu "65816"
.segment "CODE"
.org $2D83
map_control_0f2d83:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
