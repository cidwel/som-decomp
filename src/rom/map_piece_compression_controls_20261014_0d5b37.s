.setcpu "65816"
.segment "CODE"
.org $5B37
map_control_0d5b37:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
