.setcpu "65816"
.segment "CODE"
.org $2C0C
map_control_0e2c0c:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
