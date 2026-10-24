.setcpu "65816"
.segment "CODE"
.org $22AD
map_control_0e22ad:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
