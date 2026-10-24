.setcpu "65816"
.segment "CODE"
.org $8F22
map_control_0c8f22:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
