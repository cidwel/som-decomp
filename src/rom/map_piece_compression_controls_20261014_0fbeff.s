.setcpu "65816"
.segment "CODE"
.org $BEFF
map_control_0fbeff:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
