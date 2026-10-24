.setcpu "65816"
.segment "CODE"
.org $8619
map_control_0d8619:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
