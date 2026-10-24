.setcpu "65816"
.segment "CODE"
.org $26A3
map_control_0d26a3:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
