.setcpu "65816"
.segment "CODE"
.org $31F3
map_control_0f31f3:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
