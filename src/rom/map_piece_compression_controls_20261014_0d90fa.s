.setcpu "65816"
.segment "CODE"
.org $90FA
map_control_0d90fa:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
