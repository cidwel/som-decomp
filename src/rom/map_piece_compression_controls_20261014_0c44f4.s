.setcpu "65816"
.segment "CODE"
.org $44F4
map_control_0c44f4:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
