.setcpu "65816"
.segment "CODE"
.org $CBBE
map_control_0fcbbe:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
