.setcpu "65816"
.segment "CODE"
.org $D9C0
map_control_0ed9c0:
    .byte $D9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
