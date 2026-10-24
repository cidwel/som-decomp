.setcpu "65816"
.segment "CODE"
.org $7412
map_control_0c7412:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
