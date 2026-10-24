.setcpu "65816"
.segment "CODE"
.org $4473
map_control_0c4473:
    .byte $EE ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
