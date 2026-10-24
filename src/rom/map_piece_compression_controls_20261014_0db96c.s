.setcpu "65816"
.segment "CODE"
.org $B96C
map_control_0db96c:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
