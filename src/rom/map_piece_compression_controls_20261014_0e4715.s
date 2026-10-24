.setcpu "65816"
.segment "CODE"
.org $4715
map_control_0e4715:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
