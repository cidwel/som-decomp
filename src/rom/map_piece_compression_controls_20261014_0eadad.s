.setcpu "65816"
.segment "CODE"
.org $ADAD
map_control_0eadad:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
