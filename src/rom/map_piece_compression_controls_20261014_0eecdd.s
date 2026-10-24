.setcpu "65816"
.segment "CODE"
.org $ECDD
map_control_0eecdd:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
