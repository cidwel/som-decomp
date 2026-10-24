.setcpu "65816"
.segment "CODE"
.org $8F78
map_control_0e8f78:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
