.setcpu "65816"
.segment "CODE"
.org $B7F9
map_control_0db7f9:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
