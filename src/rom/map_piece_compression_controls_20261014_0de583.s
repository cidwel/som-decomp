.setcpu "65816"
.segment "CODE"
.org $E583
map_control_0de583:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
