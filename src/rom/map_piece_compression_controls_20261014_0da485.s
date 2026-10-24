.setcpu "65816"
.segment "CODE"
.org $A485
map_control_0da485:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
