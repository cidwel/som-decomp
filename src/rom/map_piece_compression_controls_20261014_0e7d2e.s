.setcpu "65816"
.segment "CODE"
.org $7D2E
map_control_0e7d2e:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
