.setcpu "65816"
.segment "CODE"
.org $5539
map_control_0d5539:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
