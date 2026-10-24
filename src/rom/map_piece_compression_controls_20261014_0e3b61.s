.setcpu "65816"
.segment "CODE"
.org $3B61
map_control_0e3b61:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
