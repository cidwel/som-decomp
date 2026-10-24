.setcpu "65816"
.segment "CODE"
.org $7048
map_control_0d7048:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
