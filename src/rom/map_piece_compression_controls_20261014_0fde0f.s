.setcpu "65816"
.segment "CODE"
.org $DE0F
map_control_0fde0f:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
