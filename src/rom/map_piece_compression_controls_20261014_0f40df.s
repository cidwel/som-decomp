.setcpu "65816"
.segment "CODE"
.org $40DF
map_control_0f40df:
    .byte $F2 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
