.setcpu "65816"
.segment "CODE"
.org $E90F
map_control_0de90f:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
