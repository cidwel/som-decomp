.setcpu "65816"
.segment "CODE"
.org $37B7
map_control_0d37b7:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
