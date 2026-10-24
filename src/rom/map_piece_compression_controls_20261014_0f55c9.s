.setcpu "65816"
.segment "CODE"
.org $55C9
map_control_0f55c9:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
