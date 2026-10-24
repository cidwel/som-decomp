.setcpu "65816"
.segment "CODE"
.org $7504
map_control_0c7504:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
