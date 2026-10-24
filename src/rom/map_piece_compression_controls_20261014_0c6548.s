.setcpu "65816"
.segment "CODE"
.org $6548
map_control_0c6548:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
