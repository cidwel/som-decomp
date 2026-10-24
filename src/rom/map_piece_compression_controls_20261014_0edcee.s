.setcpu "65816"
.segment "CODE"
.org $DCEE
map_control_0edcee:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
