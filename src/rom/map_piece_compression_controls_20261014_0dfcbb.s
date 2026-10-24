.setcpu "65816"
.segment "CODE"
.org $FCBB
map_control_0dfcbb:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
