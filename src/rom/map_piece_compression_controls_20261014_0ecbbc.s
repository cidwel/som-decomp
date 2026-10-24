.setcpu "65816"
.segment "CODE"
.org $CBBC
map_control_0ecbbc:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
