.setcpu "65816"
.segment "CODE"
.org $8DF7
map_control_0d8df7:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
