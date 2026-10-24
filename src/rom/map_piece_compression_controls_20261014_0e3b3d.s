.setcpu "65816"
.segment "CODE"
.org $3B3D
map_control_0e3b3d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
