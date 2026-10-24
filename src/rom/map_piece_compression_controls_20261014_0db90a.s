.setcpu "65816"
.segment "CODE"
.org $B90A
map_control_0db90a:
    .byte $E4 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
