.setcpu "65816"
.segment "CODE"
.org $2E14
map_control_0d2e14:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
