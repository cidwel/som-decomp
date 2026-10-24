.setcpu "65816"
.segment "CODE"
.org $B00D
map_control_0db00d:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
