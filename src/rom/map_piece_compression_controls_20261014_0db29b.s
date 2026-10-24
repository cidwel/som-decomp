.setcpu "65816"
.segment "CODE"
.org $B29B
map_control_0db29b:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
