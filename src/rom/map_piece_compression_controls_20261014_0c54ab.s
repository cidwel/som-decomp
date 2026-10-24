.setcpu "65816"
.segment "CODE"
.org $54AB
map_control_0c54ab:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
