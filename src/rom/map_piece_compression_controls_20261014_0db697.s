.setcpu "65816"
.segment "CODE"
.org $B697
map_control_0db697:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
