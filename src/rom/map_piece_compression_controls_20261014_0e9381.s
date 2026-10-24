.setcpu "65816"
.segment "CODE"
.org $9381
map_control_0e9381:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
