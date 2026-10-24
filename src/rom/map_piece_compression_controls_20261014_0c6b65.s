.setcpu "65816"
.segment "CODE"
.org $6B65
map_control_0c6b65:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
