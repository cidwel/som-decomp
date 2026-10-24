.setcpu "65816"
.segment "CODE"
.org $9285
map_control_0d9285:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
