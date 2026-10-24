.setcpu "65816"
.segment "CODE"
.org $2D59
map_control_0f2d59:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
