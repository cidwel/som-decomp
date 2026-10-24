.setcpu "65816"
.segment "CODE"
.org $83DA
map_control_0d83da:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
