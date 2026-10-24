.setcpu "65816"
.segment "CODE"
.org $A22E
map_control_0ea22e:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
