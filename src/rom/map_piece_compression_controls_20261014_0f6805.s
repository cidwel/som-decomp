.setcpu "65816"
.segment "CODE"
.org $6805
map_control_0f6805:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
