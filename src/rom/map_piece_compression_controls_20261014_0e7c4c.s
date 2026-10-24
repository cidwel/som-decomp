.setcpu "65816"
.segment "CODE"
.org $7C4C
map_control_0e7c4c:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
