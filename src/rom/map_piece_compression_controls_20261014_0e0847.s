.setcpu "65816"
.segment "CODE"
.org $0847
map_control_0e0847:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
