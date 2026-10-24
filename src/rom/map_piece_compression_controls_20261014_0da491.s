.setcpu "65816"
.segment "CODE"
.org $A491
map_control_0da491:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
