.setcpu "65816"
.segment "CODE"
.org $5F21
map_control_0e5f21:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
