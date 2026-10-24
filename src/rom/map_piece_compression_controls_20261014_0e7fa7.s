.setcpu "65816"
.segment "CODE"
.org $7FA7
map_control_0e7fa7:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
