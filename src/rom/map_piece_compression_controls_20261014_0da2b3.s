.setcpu "65816"
.segment "CODE"
.org $A2B3
map_control_0da2b3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
