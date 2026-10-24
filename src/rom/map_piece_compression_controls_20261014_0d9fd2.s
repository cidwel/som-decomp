.setcpu "65816"
.segment "CODE"
.org $9FD2
map_control_0d9fd2:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
