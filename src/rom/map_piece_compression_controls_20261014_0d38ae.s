.setcpu "65816"
.segment "CODE"
.org $38AE
map_control_0d38ae:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
