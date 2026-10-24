.setcpu "65816"
.segment "CODE"
.org $F2AF
map_control_0df2af:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
