.setcpu "65816"
.segment "CODE"
.org $3626
map_control_0e3626:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
