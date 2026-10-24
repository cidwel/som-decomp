.setcpu "65816"
.segment "CODE"
.org $4B65
map_control_0f4b65:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
