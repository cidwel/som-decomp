.setcpu "65816"
.segment "CODE"
.org $29D9
map_control_0e29d9:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
