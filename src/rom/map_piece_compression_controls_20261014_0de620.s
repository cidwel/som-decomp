.setcpu "65816"
.segment "CODE"
.org $E620
map_control_0de620:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
