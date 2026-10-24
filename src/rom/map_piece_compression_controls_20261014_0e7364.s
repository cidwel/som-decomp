.setcpu "65816"
.segment "CODE"
.org $7364
map_control_0e7364:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
