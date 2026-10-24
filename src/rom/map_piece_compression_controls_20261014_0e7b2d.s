.setcpu "65816"
.segment "CODE"
.org $7B2D
map_control_0e7b2d:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
