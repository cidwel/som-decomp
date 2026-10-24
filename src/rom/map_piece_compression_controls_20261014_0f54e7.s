.setcpu "65816"
.segment "CODE"
.org $54E7
map_control_0f54e7:
    .byte $D7 ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
