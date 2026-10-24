.setcpu "65816"
.segment "CODE"
.org $431D
map_control_0c431d:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
