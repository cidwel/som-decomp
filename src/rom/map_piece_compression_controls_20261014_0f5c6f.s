.setcpu "65816"
.segment "CODE"
.org $5C6F
map_control_0f5c6f:
    .byte $E7 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
