.setcpu "65816"
.segment "CODE"
.org $1535
map_control_0e1535:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
