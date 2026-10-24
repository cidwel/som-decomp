.setcpu "65816"
.segment "CODE"
.org $F2C7
map_control_0df2c7:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
