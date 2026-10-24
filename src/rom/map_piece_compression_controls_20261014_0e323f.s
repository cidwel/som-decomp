.setcpu "65816"
.segment "CODE"
.org $323F
map_control_0e323f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
