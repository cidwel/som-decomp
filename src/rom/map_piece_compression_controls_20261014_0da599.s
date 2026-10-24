.setcpu "65816"
.segment "CODE"
.org $A599
map_control_0da599:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
