.setcpu "65816"
.segment "CODE"
.org $8730
map_control_0c8730:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
