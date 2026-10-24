.setcpu "65816"
.segment "CODE"
.org $9512
map_control_0d9512:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
