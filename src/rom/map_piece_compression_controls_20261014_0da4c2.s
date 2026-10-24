.setcpu "65816"
.segment "CODE"
.org $A4C2
map_control_0da4c2:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
