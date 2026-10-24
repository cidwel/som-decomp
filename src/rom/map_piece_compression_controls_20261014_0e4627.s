.setcpu "65816"
.segment "CODE"
.org $4627
map_control_0e4627:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
