.setcpu "65816"
.segment "CODE"
.org $EF4C
map_control_0eef4c:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
