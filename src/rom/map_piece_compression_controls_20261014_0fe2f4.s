.setcpu "65816"
.segment "CODE"
.org $E2F4
map_control_0fe2f4:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
