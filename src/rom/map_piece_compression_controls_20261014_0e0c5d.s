.setcpu "65816"
.segment "CODE"
.org $0C5D
map_control_0e0c5d:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
