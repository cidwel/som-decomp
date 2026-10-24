.setcpu "65816"
.segment "CODE"
.org $7A83
map_control_0f7a83:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
