.setcpu "65816"
.segment "CODE"
.org $33DE
map_control_0d33de:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
