.setcpu "65816"
.segment "CODE"
.org $94CB
map_control_0d94cb:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
