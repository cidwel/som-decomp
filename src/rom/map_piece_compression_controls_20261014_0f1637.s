.setcpu "65816"
.segment "CODE"
.org $1637
map_control_0f1637:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
