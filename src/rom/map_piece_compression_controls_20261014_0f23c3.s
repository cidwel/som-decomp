.setcpu "65816"
.segment "CODE"
.org $23C3
map_control_0f23c3:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
