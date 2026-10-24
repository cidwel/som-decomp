.setcpu "65816"
.segment "CODE"
.org $A8BA
map_control_0da8ba:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
