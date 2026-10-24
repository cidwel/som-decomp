.setcpu "65816"
.segment "CODE"
.org $50E9
map_control_0e50e9:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
