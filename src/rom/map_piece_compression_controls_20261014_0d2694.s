.setcpu "65816"
.segment "CODE"
.org $2694
map_control_0d2694:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
