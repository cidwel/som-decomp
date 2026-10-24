.setcpu "65816"
.segment "CODE"
.org $4DC1
map_control_0e4dc1:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
