.setcpu "65816"
.segment "CODE"
.org $F520
map_control_0ff520:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
