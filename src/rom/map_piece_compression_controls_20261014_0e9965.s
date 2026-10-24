.setcpu "65816"
.segment "CODE"
.org $9965
map_control_0e9965:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
