.setcpu "65816"
.segment "CODE"
.org $7D66
map_control_0c7d66:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
