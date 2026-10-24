.setcpu "65816"
.segment "CODE"
.org $F0ED
map_control_0ff0ed:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
