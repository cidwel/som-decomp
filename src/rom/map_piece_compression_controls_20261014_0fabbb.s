.setcpu "65816"
.segment "CODE"
.org $ABBB
map_control_0fabbb:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
