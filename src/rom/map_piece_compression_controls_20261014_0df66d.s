.setcpu "65816"
.segment "CODE"
.org $F66D
map_control_0df66d:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
