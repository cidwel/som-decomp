.setcpu "65816"
.segment "CODE"
.org $EBD3
map_control_0debd3:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
