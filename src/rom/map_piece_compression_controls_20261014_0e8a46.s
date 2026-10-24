.setcpu "65816"
.segment "CODE"
.org $8A46
map_control_0e8a46:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
