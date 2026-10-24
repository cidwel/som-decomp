.setcpu "65816"
.segment "CODE"
.org $7077
map_control_0e7077:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
