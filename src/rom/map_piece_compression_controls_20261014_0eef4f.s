.setcpu "65816"
.segment "CODE"
.org $EF4F
map_control_0eef4f:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
