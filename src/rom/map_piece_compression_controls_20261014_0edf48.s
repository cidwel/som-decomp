.setcpu "65816"
.segment "CODE"
.org $DF48
map_control_0edf48:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
