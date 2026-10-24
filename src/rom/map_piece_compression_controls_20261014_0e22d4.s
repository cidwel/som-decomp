.setcpu "65816"
.segment "CODE"
.org $22D4
map_control_0e22d4:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
