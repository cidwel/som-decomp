.setcpu "65816"
.segment "CODE"
.org $26D2
map_control_0c26d2:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
