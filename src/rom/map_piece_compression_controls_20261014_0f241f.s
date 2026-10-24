.setcpu "65816"
.segment "CODE"
.org $241F
map_control_0f241f:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
