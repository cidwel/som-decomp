.setcpu "65816"
.segment "CODE"
.org $3D89
map_control_0c3d89:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
