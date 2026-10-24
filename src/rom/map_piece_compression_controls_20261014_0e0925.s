.setcpu "65816"
.segment "CODE"
.org $0925
map_control_0e0925:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
