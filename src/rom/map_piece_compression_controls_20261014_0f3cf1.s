.setcpu "65816"
.segment "CODE"
.org $3CF1
map_control_0f3cf1:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
