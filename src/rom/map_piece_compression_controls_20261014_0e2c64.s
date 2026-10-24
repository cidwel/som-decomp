.setcpu "65816"
.segment "CODE"
.org $2C64
map_control_0e2c64:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
