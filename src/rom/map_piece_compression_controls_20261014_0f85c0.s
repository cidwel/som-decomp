.setcpu "65816"
.segment "CODE"
.org $85C0
map_control_0f85c0:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
