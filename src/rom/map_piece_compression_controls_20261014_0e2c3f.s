.setcpu "65816"
.segment "CODE"
.org $2C3F
map_control_0e2c3f:
    .byte $D2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
