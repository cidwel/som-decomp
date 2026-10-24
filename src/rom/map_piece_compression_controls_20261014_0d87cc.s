.setcpu "65816"
.segment "CODE"
.org $87CC
map_control_0d87cc:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
