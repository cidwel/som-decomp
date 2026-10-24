.setcpu "65816"
.segment "CODE"
.org $7483
map_control_0c7483:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
