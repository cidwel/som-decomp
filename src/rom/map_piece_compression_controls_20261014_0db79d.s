.setcpu "65816"
.segment "CODE"
.org $B79D
map_control_0db79d:
    .byte $C6 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
