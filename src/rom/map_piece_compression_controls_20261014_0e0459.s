.setcpu "65816"
.segment "CODE"
.org $0459
map_control_0e0459:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
