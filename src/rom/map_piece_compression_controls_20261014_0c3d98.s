.setcpu "65816"
.segment "CODE"
.org $3D98
map_control_0c3d98:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
