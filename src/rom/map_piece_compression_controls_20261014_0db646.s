.setcpu "65816"
.segment "CODE"
.org $B646
map_control_0db646:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
