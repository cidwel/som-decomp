.setcpu "65816"
.segment "CODE"
.org $22E6
map_control_0d22e6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
