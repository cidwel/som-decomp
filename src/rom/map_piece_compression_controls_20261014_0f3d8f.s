.setcpu "65816"
.segment "CODE"
.org $3D8F
map_control_0f3d8f:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
