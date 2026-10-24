.setcpu "65816"
.segment "CODE"
.org $7A41
map_control_0e7a41:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
