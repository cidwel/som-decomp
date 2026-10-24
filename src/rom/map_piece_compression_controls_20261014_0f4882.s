.setcpu "65816"
.segment "CODE"
.org $4882
map_control_0f4882:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
