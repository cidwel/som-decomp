.setcpu "65816"
.segment "CODE"
.org $BEED
map_control_0fbeed:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
