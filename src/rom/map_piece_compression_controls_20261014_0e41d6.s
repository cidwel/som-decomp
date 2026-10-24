.setcpu "65816"
.segment "CODE"
.org $41D6
map_control_0e41d6:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
