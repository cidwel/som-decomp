.setcpu "65816"
.segment "CODE"
.org $B5FE
map_control_0db5fe:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
