.setcpu "65816"
.segment "CODE"
.org $6AE9
map_control_0c6ae9:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
