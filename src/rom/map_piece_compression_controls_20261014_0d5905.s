.setcpu "65816"
.segment "CODE"
.org $5905
map_control_0d5905:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
