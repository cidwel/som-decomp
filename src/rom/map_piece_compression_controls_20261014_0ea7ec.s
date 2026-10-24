.setcpu "65816"
.segment "CODE"
.org $A7EC
map_control_0ea7ec:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
