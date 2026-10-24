.setcpu "65816"
.segment "CODE"
.org $3442
map_control_0f3442:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
