.setcpu "65816"
.segment "CODE"
.org $B3F6
map_control_0fb3f6:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
