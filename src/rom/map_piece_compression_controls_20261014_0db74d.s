.setcpu "65816"
.segment "CODE"
.org $B74D
map_control_0db74d:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
