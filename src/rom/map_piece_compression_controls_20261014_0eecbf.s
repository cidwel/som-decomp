.setcpu "65816"
.segment "CODE"
.org $ECBF
map_control_0eecbf:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $C4 ; same-value copy count/distance
