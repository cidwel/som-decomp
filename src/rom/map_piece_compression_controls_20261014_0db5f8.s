.setcpu "65816"
.segment "CODE"
.org $B5F8
map_control_0db5f8:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
