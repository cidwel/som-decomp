.setcpu "65816"
.segment "CODE"
.org $2CC2
map_control_0f2cc2:
    .byte $CC ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
