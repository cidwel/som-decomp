.setcpu "65816"
.segment "CODE"
.org $CCBB
map_control_0eccbb:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
