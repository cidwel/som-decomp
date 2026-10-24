.setcpu "65816"
.segment "CODE"
.org $2D51
map_control_0f2d51:
    .byte $E8 ; backreference distance high bits
    .byte $AA ; distance low bit/count
