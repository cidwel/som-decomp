.setcpu "65816"
.segment "CODE"
.org $54D9
map_control_0d54d9:
    .byte $F1 ; progressive-copy count
    .byte $C5 ; same-value copy count/distance
