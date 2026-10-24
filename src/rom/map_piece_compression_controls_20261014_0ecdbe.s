.setcpu "65816"
.segment "CODE"
.org $CDBE
map_control_0ecdbe:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
