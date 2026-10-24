.setcpu "65816"
.segment "CODE"
.org $5D65
map_control_0e5d65:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
