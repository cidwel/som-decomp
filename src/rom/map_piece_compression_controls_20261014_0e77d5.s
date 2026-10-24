.setcpu "65816"
.segment "CODE"
.org $77D5
map_control_0e77d5:
    .byte $C9 ; same-value copy count/distance
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
