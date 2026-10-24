.setcpu "65816"
.segment "CODE"
.org $5722
map_control_0d5722:
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
