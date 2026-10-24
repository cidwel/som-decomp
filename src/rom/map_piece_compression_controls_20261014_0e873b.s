.setcpu "65816"
.segment "CODE"
.org $873B
map_control_0e873b:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
