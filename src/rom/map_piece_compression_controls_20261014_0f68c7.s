.setcpu "65816"
.segment "CODE"
.org $68C7
map_control_0f68c7:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
