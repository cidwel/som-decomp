.setcpu "65816"
.segment "CODE"
.org $AE44
map_control_0eae44:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
