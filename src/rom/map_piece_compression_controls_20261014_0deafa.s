.setcpu "65816"
.segment "CODE"
.org $EAFA
map_control_0deafa:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
