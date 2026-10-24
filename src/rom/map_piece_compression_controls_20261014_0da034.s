.setcpu "65816"
.segment "CODE"
.org $A034
map_control_0da034:
    .byte $C9 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
