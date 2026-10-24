.setcpu "65816"
.segment "CODE"
.org $C7AC
map_control_0ec7ac:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
