.setcpu "65816"
.segment "CODE"
.org $10F4
map_control_0c10f4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
