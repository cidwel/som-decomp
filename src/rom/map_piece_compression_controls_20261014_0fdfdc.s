.setcpu "65816"
.segment "CODE"
.org $DFDC
map_control_0fdfdc:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
