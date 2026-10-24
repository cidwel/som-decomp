.setcpu "65816"
.segment "CODE"
.org $12A6
map_control_0e12a6:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
