.setcpu "65816"
.segment "CODE"
.org $2511
map_control_0d2511:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
