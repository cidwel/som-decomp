.setcpu "65816"
.segment "CODE"
.org $12F3
map_control_0e12f3:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
