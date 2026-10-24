.setcpu "65816"
.segment "CODE"
.org $B670
map_control_0db670:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
