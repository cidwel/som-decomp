.setcpu "65816"
.segment "CODE"
.org $6CE7
map_control_0c6ce7:
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
