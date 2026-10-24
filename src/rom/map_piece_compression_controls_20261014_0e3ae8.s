.setcpu "65816"
.segment "CODE"
.org $3AE8
map_control_0e3ae8:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
