.setcpu "65816"
.segment "CODE"
.org $9BE8
map_control_0e9be8:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
