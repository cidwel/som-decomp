.setcpu "65816"
.segment "CODE"
.org $84D1
map_control_0f84d1:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
