.setcpu "65816"
.segment "CODE"
.org $2259
map_control_0d2259:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
