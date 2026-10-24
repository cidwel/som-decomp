.setcpu "65816"
.segment "CODE"
.org $B7C9
map_control_0db7c9:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
