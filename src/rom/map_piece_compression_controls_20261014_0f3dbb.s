.setcpu "65816"
.segment "CODE"
.org $3DBB
map_control_0f3dbb:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
