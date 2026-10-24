.setcpu "65816"
.segment "CODE"
.org $6899
map_control_0d6899:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
