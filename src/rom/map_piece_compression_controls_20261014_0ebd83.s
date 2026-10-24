.setcpu "65816"
.segment "CODE"
.org $BD83
map_control_0ebd83:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
