.setcpu "65816"
.segment "CODE"
.org $1321
map_control_0f1321:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
