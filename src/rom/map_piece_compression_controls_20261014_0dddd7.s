.setcpu "65816"
.segment "CODE"
.org $DDD7
map_control_0dddd7:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
