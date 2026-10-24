.setcpu "65816"
.segment "CODE"
.org $6FC0
map_control_0e6fc0:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
