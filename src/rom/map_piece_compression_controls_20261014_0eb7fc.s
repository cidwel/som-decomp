.setcpu "65816"
.segment "CODE"
.org $B7FC
map_control_0eb7fc:
    .byte $EE ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
