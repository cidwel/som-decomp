.setcpu "65816"
.segment "CODE"
.org $E6FC
map_control_0de6fc:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
