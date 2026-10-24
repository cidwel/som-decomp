.setcpu "65816"
.segment "CODE"
.org $DE6F
map_control_0dde6f:
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
