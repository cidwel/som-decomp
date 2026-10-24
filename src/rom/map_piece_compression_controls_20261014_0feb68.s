.setcpu "65816"
.segment "CODE"
.org $EB68
map_control_0feb68:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
