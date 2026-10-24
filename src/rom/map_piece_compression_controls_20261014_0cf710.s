.setcpu "65816"
.segment "CODE"
.org $F710
map_control_0cf710:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
