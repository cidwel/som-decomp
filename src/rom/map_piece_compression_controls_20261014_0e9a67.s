.setcpu "65816"
.segment "CODE"
.org $9A67
map_control_0e9a67:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
