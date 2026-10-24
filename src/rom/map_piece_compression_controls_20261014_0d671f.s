.setcpu "65816"
.segment "CODE"
.org $671F
map_control_0d671f:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
