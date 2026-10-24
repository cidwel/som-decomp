.setcpu "65816"
.segment "CODE"
.org $B693
map_control_0db693:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
