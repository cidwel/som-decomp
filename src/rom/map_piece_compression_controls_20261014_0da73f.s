.setcpu "65816"
.segment "CODE"
.org $A73F
map_control_0da73f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
