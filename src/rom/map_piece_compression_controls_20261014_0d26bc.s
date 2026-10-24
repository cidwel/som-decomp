.setcpu "65816"
.segment "CODE"
.org $26BC
map_control_0d26bc:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
