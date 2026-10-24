.setcpu "65816"
.segment "CODE"
.org $3C81
map_control_0f3c81:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
