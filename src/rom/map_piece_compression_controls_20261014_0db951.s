.setcpu "65816"
.segment "CODE"
.org $B951
map_control_0db951:
    .byte $E4 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
