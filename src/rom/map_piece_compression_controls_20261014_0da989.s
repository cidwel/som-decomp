.setcpu "65816"
.segment "CODE"
.org $A989
map_control_0da989:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
