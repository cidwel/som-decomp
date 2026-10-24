.setcpu "65816"
.segment "CODE"
.org $DCF4
map_control_0fdcf4:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
