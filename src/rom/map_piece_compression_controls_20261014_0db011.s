.setcpu "65816"
.segment "CODE"
.org $B011
map_control_0db011:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
