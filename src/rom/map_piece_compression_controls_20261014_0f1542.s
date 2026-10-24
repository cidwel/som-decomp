.setcpu "65816"
.segment "CODE"
.org $1542
map_control_0f1542:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
