.setcpu "65816"
.segment "CODE"
.org $09F0
map_control_0e09f0:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
