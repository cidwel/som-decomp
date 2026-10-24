.setcpu "65816"
.segment "CODE"
.org $7476
map_control_0c7476:
    .byte $D9 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
