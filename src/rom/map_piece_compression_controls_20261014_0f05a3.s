.setcpu "65816"
.segment "CODE"
.org $05A3
map_control_0f05a3:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
