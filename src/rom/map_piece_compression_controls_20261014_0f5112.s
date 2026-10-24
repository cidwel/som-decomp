.setcpu "65816"
.segment "CODE"
.org $5112
map_control_0f5112:
    .byte $D1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
