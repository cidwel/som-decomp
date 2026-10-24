.setcpu "65816"
.segment "CODE"
.org $7628
map_control_0c7628:
    .byte $C7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
