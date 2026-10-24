.setcpu "65816"
.segment "CODE"
.org $9603
map_control_0d9603:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
