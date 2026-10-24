.setcpu "65816"
.segment "CODE"
.org $B7E1
map_control_0db7e1:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
