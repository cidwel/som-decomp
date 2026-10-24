.setcpu "65816"
.segment "CODE"
.org $5723
map_control_0c5723:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
