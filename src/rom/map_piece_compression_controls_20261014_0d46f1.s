.setcpu "65816"
.segment "CODE"
.org $46F1
map_control_0d46f1:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
