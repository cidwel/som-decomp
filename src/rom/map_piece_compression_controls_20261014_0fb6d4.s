.setcpu "65816"
.segment "CODE"
.org $B6D4
map_control_0fb6d4:
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
