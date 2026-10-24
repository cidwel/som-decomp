.setcpu "65816"
.segment "CODE"
.org $19A6
map_control_0c19a6:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
