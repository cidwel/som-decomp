.setcpu "65816"
.segment "CODE"
.org $3642
map_control_0f3642:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
