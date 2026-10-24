.setcpu "65816"
.segment "CODE"
.org $6A29
map_control_0e6a29:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
