.setcpu "65816"
.segment "CODE"
.org $EF3A
map_control_0eef3a:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
