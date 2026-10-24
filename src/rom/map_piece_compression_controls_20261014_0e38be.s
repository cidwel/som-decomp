.setcpu "65816"
.segment "CODE"
.org $38BE
map_control_0e38be:
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
