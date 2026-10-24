.setcpu "65816"
.segment "CODE"
.org $62B9
map_control_0d62b9:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
