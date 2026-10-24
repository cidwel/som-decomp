.setcpu "65816"
.segment "CODE"
.org $A7E7
map_control_0da7e7:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
