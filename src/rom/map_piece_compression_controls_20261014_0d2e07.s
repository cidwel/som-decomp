.setcpu "65816"
.segment "CODE"
.org $2E07
map_control_0d2e07:
    .byte $D9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
