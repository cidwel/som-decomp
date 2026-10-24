.setcpu "65816"
.segment "CODE"
.org $E351
map_control_0fe351:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
