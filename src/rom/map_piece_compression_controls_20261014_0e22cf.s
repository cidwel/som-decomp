.setcpu "65816"
.segment "CODE"
.org $22CF
map_control_0e22cf:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
