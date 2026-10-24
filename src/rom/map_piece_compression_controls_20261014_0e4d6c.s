.setcpu "65816"
.segment "CODE"
.org $4D6C
map_control_0e4d6c:
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
