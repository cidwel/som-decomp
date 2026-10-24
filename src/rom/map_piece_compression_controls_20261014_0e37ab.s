.setcpu "65816"
.segment "CODE"
.org $37AB
map_control_0e37ab:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
