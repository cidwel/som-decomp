.setcpu "65816"
.segment "CODE"
.org $3229
map_control_0d3229:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
