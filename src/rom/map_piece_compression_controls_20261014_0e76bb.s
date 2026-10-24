.setcpu "65816"
.segment "CODE"
.org $76BB
map_control_0e76bb:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
