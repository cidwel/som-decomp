.setcpu "65816"
.segment "CODE"
.org $44CC
map_control_0c44cc:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
