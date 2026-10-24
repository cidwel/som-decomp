.setcpu "65816"
.segment "CODE"
.org $EE4C
map_control_0eee4c:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
