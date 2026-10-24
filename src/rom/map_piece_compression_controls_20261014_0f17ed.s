.setcpu "65816"
.segment "CODE"
.org $17ED
map_control_0f17ed:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
