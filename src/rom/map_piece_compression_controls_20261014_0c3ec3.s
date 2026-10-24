.setcpu "65816"
.segment "CODE"
.org $3EC3
map_control_0c3ec3:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
