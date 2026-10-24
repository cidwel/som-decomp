.setcpu "65816"
.segment "CODE"
.org $A9EE
map_control_0da9ee:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
