.setcpu "65816"
.segment "CODE"
.org $B722
map_control_0db722:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
