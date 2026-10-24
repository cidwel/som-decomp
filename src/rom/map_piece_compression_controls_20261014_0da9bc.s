.setcpu "65816"
.segment "CODE"
.org $A9BC
map_control_0da9bc:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
