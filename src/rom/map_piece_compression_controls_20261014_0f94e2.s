.setcpu "65816"
.segment "CODE"
.org $94E2
map_control_0f94e2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
