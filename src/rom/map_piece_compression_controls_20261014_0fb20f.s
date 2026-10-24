.setcpu "65816"
.segment "CODE"
.org $B20F
map_control_0fb20f:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
