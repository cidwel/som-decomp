.setcpu "65816"
.segment "CODE"
.org $3DD1
map_control_0f3dd1:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
