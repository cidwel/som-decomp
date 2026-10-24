.setcpu "65816"
.segment "CODE"
.org $0E0F
map_control_0c0e0f:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
