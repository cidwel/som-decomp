.setcpu "65816"
.segment "CODE"
.org $8E25
map_control_0d8e25:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
