.setcpu "65816"
.segment "CODE"
.org $4398
map_control_0c4398:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
