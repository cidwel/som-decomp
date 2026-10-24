.setcpu "65816"
.segment "CODE"
.org $26AB
map_control_0d26ab:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
